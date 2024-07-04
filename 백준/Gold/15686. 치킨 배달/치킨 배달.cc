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
vector<vector<int>> vec;
void init(){
    cin >> N >> M;
    input.resize(N,vector<int>(N,0));

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> input[i][j];

            if(input[i][j]==2)
                chicken.push_back(make_pair(i,j));
            else if(input[i][j]==1)
                home.push_back(make_pair(i,j));
        }
    }

    vec.resize(home.size());
}

void distance(){
    for(int i=0; i<home.size(); i++){
        pair<int,int> h = home[i];
        for(pair<int,int> c : chicken){
            int _y = abs(h.first-c.first);
            int _x = abs(h.second - c.second);

            vec[i].push_back(_y+_x);
        }
    }
}

void solve(){
    distance();

    vector<int> order(chicken.size(),0);
    for(int i=0; i<M; i++){
        order[i] = 1;
    }

    int result = INF;
    do{
        int sumN = 0;
        for(int i=0; i<vec.size(); i++){
            int minN = INF;
            for(int j=0; j<order.size(); j++){
                if(order[j]==1)
                    minN = min(minN, vec[i][j]);
            }
            sumN += minN;
        }
        result = min(result, sumN);
    }
    while(prev_permutation(order.begin(), order.end()));

    cout << result << "\n";
}

int main(){
    init();
    solve();
    return 0;
}