//
// Created by yooki on 2024/03/05.
//
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 10000001

using namespace std;

int n,k;
vector<int> input;
vector<int> dp;

void init(){
    cin >> n >> k;
    dp.clear();
    dp.resize(k+1,INF);

    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        input.push_back(num);
    }

    sort(input.begin(), input.end());
}

void solve(){
    for(int i=1; i<k+1; i++){
        for(int j=0; j<n; j++){
            int num = input[j];
            if(i%num==0)
                dp[i] = min(dp[i],i/num);
            if(i-num>0)
                dp[i] = min(dp[i], dp[i-num] + 1);
        }
    }

    if(dp[k]==INF)
        cout << -1 << "\n";
    else
        cout << dp[k] << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
    return 0;
}