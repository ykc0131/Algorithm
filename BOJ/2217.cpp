//
// Created by yooki on 2024/01/11.
//
#include <iostream>
#include <map>

using namespace std;

int N;
map<int,int> m;

void init(){
    cin >> N;
    for(int i=0; i<N; i++){
        int n;
        cin >> n;
        m[n] += 1;
    }
}

void solve(){
    int max = 0;
    for(auto iter=m.begin(); iter!=m.end(); iter++){
        int n = iter->first;
        int cnt = iter->second;

        int result = n*N;
        max = max > result ? max : result;
        N-=cnt;
    }
    cout << max << "\n";
}

int main(){
    init();
    solve();
    return 0;
}