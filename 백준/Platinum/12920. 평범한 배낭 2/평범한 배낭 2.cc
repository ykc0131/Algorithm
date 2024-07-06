//
// Created by yooki on 2024/07/07.
//
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int N,M;
vector<pair<int,int>> input;
vector<vector<int>> vec;

void init(){
    cin >> N >> M;

    input.push_back({0,0});
    for(int i=0; i<N; i++){
        int V,C,K;
        cin >> V >> C >> K;

        for(int j=1; K>0; j<<=1 ){
            int ix = min(j,K);
            input.push_back({V*ix, C*ix});
            K -= ix;
        }
    }

    vec.resize(input.size(), vector<int>(M+1,0));
}

void solve(){
    for(int i=1; i<input.size(); i++){
        int w = input[i].first;
        int v = input[i].second;

        for(int j=1; j<M+1; j++){
            vec[i][j] = vec[i-1][j];

            if(j-w>=0)
                vec[i][j] = max(vec[i][j], vec[i-1][j-w] + v);
        }
    }

    cout << vec[input.size()-1][M] << "\n";
}

int main(){
    init();
    solve();
    return 0;
}