#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<long long> dp(N+1,0);
    dp[1]=3,dp[2]=7;

    for(int i=3;i<N+1;i++){
        dp[i]=(dp[i-2]+2*dp[i-1])%9901;
    }
    cout << dp[N]%9901 << endl;

    return 0;
}