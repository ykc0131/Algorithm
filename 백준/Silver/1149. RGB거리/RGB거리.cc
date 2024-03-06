//
// Created by yooki on 2024/03/06.
//
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000001

using namespace std;

int N;
vector<vector<int>> rgb;
void init(){
    cin >> N;
    rgb.resize(N,vector<int>(3,0));

    for(int i=0; i<N; i++){
        for(int j=0; j<3; j++){
            cin >> rgb[i][j];
        }
    }
}

void solve(){
    for(int i=1; i<N; i++){
        for(int j=0; j<3; j++){
            rgb[i][j] += min(rgb[i-1][(j+1)%3], rgb[i-1][(j+2)%3]);
        }
    }

    int result = INF;
    for(int i=0; i<3; i++){
        result = min(result, rgb[N-1][i]);
    }
    cout << result << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
    return 0;
}