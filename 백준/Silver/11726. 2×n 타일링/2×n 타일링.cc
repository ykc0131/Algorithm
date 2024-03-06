//
// Created by yooki on 2024/03/06.
//
#include <iostream>

using namespace std;

int n;
int dp[1001] = {0,};
void init(){
    cin >> n;
    dp[1] = 1;
    dp[2] = 2;
}

void solve(){
    for(int i=3; i<n+1; i++){
        dp[i] = (dp[i-1]%10007 + dp[i-2]%10007)%10007;
    }
    cout << dp[n] << "\n";
}

int main(){
    init();
    solve();
    return 0;
}