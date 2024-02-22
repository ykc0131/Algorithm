//
// Created by yooki on 2024/02/22.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> vec;
vector<int> vecLen;

void init(){
    cin >> N;
    vec.clear();
    vecLen.clear();
    vecLen.resize(N+1,0);

    for(int i=0; i<N; i++){
        int n;
        cin >> n;
        vec.push_back(n);
    }
}

void solve(){
    for(int i=1; i<N; i++){
        for(int j=0; j<i; j++){
            if(vec[j] < vec[i]){
                vecLen[i] = max(vecLen[i], vecLen[j]+1);
            }
        }
    }

    int maxN = 0;
    for(int i=0; i<N; i++){
        maxN = max(maxN, vecLen[i]);
    }
    cout << maxN+1 << "\n";
}

int main(){
    init();
    solve();
    return 0;
}