//
// Created by yooki on 2024/03/07.
//
#include <iostream>

using namespace std;

int N;
int fibo[41][2] = {{0,0},};
void init(){
    cin >> N;
    fibo[0][0] = 1;
    fibo[1][1] = 1;
}

void solve(){
    for(int i=2; i<N+1; i++){
        fibo[i][0] = fibo[i-1][0] + fibo[i-2][0];
        fibo[i][1] = fibo[i-1][1] + fibo[i-2][1];
    }
    cout << fibo[N][0] << " " << fibo[N][1] << "\n";
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