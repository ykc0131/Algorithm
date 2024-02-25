//
// Created by yooki on 2024/02/25.
//
#include <iostream>

using namespace std;

int N;

void init(){
    cin >> N;
}

int getFive(int n){
    int cnt = 0;
    while(n%5==0){
        cnt++;
        n/=5;
    }
    return cnt;
}

void solve(){
    int result = 0;
    for(int i=1; i<N+1; i++){
        result += getFive(i);
    }
    cout << result << endl;
}

int main(){
    init();
    solve();
    return 0;
}