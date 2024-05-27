//
// Created by yooki on 2024/05/27.
//
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> vec;
vector<int> dp;
vector<int> tmp;
void init(){
    cin >> N;

    for(int i=0; i<N; i++){
        int n;
        cin >> n;
        vec.push_back(n);
        tmp.push_back(i);
    }
    dp.resize(N,1);
}

void solve(){
    int max = 0, resultIdx=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<i; j++){
            if(vec[j] < vec[i] && dp[j] + 1 > dp[i]){
                dp[i] = dp[j] + 1;
                tmp[i] = j;
            }
        }
        if(dp[i] > max){
            max = dp[i];
            resultIdx = i;
        }
    }

    vector<int> result;
    for(int i=0; i<max; i++){
        result.push_back(vec[resultIdx]);
        resultIdx = tmp[resultIdx];
    }

    cout << max << "\n";
    for(int i=max-1; i>=0; i--){
        cout << result[i] << " " ;
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
    return 0;
}
