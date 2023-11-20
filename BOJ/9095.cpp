//
// Created by yooki on 2023/11/20.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> v;

void init(){
    cin >> n;
    v.clear();
    v.resize(n+1,0);
}

void solve(){
    v[0] = 1;
    for(int i=1; i<=n+1; i++){
        int cnt = 0;
        if(i-2 >= 0)
            cnt += v[i-2];
        if(i-3 >= 0)
            cnt += v[i-3];

        cnt += v[i-1];
        v[i] += cnt;
    }
    cout << v[n] << "\n";
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