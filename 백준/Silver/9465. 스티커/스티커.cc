//
// Created by yooki on 2024/03/05.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, maxN;
vector<int> input[2];
vector<int> dp[3];

void init(){
    cin >> n;
    maxN = 0;
    for(int i=0; i<2; i++){
        input[i].resize(n,0);
        dp[i].resize(n,0);
        for(int j=0; j<n; j++){
            cin >> input[i][j];
        }
    }

    dp[2].resize(n,0);
    dp[0][0] = input[0][0];
    dp[1][0] = input[1][0];
    dp[2][0] = max(dp[0][0], dp[1][0]);
}

void solve(){
    for(int i=1; i<n; i++){
        if(i>1)
            maxN = max(maxN, dp[2][i-2]);
        //[0]
        dp[0][i] = max(input[0][i] + maxN, input[0][i] + dp[1][i-1]);

        //[1]
        dp[1][i] = max(input[1][i] + maxN, input[1][i] + dp[0][i-1]);

        //max 저장
        dp[2][i] = max(dp[0][i], dp[1][i]);
    }
    cout << dp[2][n-1] << "\n";
}

int main(){
    int T;
    cin >> T;

    while(T--){
        init();
        solve();
    }
    return 0;
}