//
// Created by yooki on 2024/03/05.
//
#include <iostream>
#include <vector>
#define INF 1000000000

using namespace std;

int N,K;
vector<vector<int>> vec;

void init(){
    cin >> N >> K;

    vec.clear();
    vec.resize(K+1,vector<int>(N+1,0));
    for(int i=0; i<N+1; i++){
        vec[1][i] = 1;
    }
}

void solve(){
    for(int i=2; i<K+1; i++){
        vec[i][0] = 1;
        for(int j=1; j<N+1; j++){
            vec[i][j] = (vec[i][j-1]%INF + vec[i-1][j]%INF)%INF;
        }
    }
    cout << vec[K][N] << "\n";
}

int main(){
    init();
    solve();
    return 0;
}