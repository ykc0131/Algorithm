//
// Created by yooki on 2024/02/13.
//
#include <iostream>
#include <vector>

using namespace std;

int A;
vector<int> vec;
vector<int> dp;

void init(){
    cin >> A;
    vec.clear();
    dp.clear();
    vec.resize(A,0);
    dp.resize(A,0);
    for(int i=0; i<A; i++){
        cin >> vec[i];
        dp[i] = vec[i];
    }
}

void solve(){
    int result = 0;
    for(int i=1; i<A; i++){
        for(int j=i-1; j>=0; j--){
            if(vec[j] < vec[i])
                dp[i] = max(dp[i], dp[j]+vec[i]);
        }
    }

    for(int i=0; i<A; i++){
        result = max(result, dp[i]);
    }
    cout << result << endl;
}

int main(){
    init();
    solve();
    return 0;
}