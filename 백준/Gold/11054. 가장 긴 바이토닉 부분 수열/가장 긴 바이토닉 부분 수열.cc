//
// Created by yooki on 2024/02/23.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> input;
vector<int> lr;
vector<int> rl;

void init(){
    cin >> N;
    input.clear();
    lr.clear();
    rl.clear();
    input.resize(N,0);
    lr.resize(N,0);
    rl.resize(N,0);
    for(int i=0; i<N; i++){
        cin >> input[i];
    }
}

void solve(){
    //왼->오
    for(int i=0; i<N; i++){
        for(int j=0; j<i; j++){
            if(input[i] > input[j]){
                lr[i] = max(lr[i],lr[j]+1);
            }
        }
    }

    //오->왼
    for(int i=N-1; i>=0; i--){
        for(int j=N-1; j>i; j--){
            if(input[i] > input[j]){
                rl[i] = max(rl[i],rl[j]+1);
            }
        }
    }

    int result = 0;
    for(int i=0; i<N; i++){
        if(lr[i]*rl[i]>=0)
            result = max(result, lr[i] + rl[i]);
    }

    cout << result+1 << endl;
}

int main(){
    init();
    solve();
    return 0;
}