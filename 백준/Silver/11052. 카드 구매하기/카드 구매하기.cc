//
// Created by yooki on 2024/07/17.
//
#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1000

using namespace std;

int N;
vector<int> vec;
vector<vector<int>> result;
void init(){
    cin >> N;

    for(int i=0; i<N; i++){
        int n;
        cin >> n;
        vec.push_back(n);
    }
    result.resize(N+1, vector<int>(N+1, 0));
}

void solve(){

    for(int i=1; i<N+1; i++){
        int cost = vec[i-1];
        for(int j=1; j<N+1; j++){
            result[i][j] = result[i-1][j];
            if(j >= i)
                result[i][j] = max(result[i][j], result[i][j-i] + cost);
        }
    }

    cout << result[N][N] << endl;
}

int  main(){
    init();
    solve();
    return  0;
}