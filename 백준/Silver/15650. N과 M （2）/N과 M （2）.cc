//
// Created by yooki on 2024/03/08.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M;
vector<int> vec;
void init(){
    cin >> N >> M;
    vec.clear();
    vec.resize(N,0);
    for(int i=0; i<M; i++){
        vec[i] = 1;
    }
}

void solve(){
    do{
        for(int i=0; i<N; i++){
            if(vec[i]){
                cout << i+1 << " ";
            }
        }
        cout << "\n";
    }
    while(prev_permutation(vec.begin(),vec.end()));
}

int main(){
    init();
    solve();
    return 0;
}