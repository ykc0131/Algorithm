//
// Created by yooki on 2024/01/01.
//
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int M, N;
vector<int> vec;

void init(){
    cin >> M >> N;
    vec.clear();
    vec.resize(N+1,0);
}

void solve(){
    for(int i=2; i<=sqrt(N); i++){
        if(vec[i]==-1)
            continue;
        for(int j=i*i; j<=N; j+=i){
            if(vec[j]==0)
                vec[j] = -1;
        }
    }

    if(M == 1)
        M = 2;
    for(int i=M; i<N+1; i++){
        if(vec[i]==0)
            cout << i << "\n";
    }
}

int main(){
    init();
    solve();
    return 0;
}