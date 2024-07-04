//
// Created by yooki on 2024/07/04.
//
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 25000

using namespace std;

int N, M;
vector<vector<int>> input;
vector<pair<int,int>> chicken;
vector<pair<int,int>> home;
vector<vector<int>> dist;
void init(){
    cin >> N >> M;
    input.resize(N,vector<int>(N,0));

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> input[i][j];

            // 치킨집 인덱스 처리
            if(input[i][j]==2)
                chicken.push_back(make_pair(i,j));
            // 집 인덱스 처리
            else if(input[i][j]==1)
                home.push_back(make_pair(i,j));
        }
    }

    dist.resize(home.size()); // 집 - 치킨집 '치킨 거리' 저장
}

// '치킨 거리' 미리 저장 하기
void distance(){
    for(int i=0; i<home.size(); i++){
        pair<int,int> h = home[i];
        for(pair<int,int> c : chicken){
            int _y = abs(h.first-c.first);
            int _x = abs(h.second - c.second);

            dist[i].push_back(_y + _x);
        }
    }
}

int result = INF;
void solve(){
    distance();

    // 치킨 집 M개 선택 하기
    vector<int> select(chicken.size(),0);
    for(int i=0; i<M; i++){
        select[i] = 1;
    }

    do{
        int sumN = 0; // 도시의 치킨 거리
        for(int i=0; i < dist.size(); i++){ // 모든 집에 대해서 반복문 돌리기
            int minN = INF;
            
            // 선택한 M개 치킨 집에 대해서 최소 거리 구하기
            for(int j=0; j<select.size(); j++){
                if(select[j]==1)
                    minN = min(minN, dist[i][j]);
            }
            
            sumN += minN;
        }
        
        result = min(result, sumN); // 도시의 치킨 거리 최소 구하기
    }
    while(prev_permutation(select.begin(), select.end()));

    cout << result << "\n";
}

int main(){
    init();
    solve();
    return 0;
}