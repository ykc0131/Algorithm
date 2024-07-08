//
// Created by yooki on 2024/07/08.
//
#include <iostream>
#include <vector>

using namespace std;

long long M, N, x, y;
void init(){
    cin >> M >> N >> x >> y;
}

// 최대 공약수 구하기
int gcd(int a, int b){
    if(b==0)
        return a;
    return gcd(b, a%b);
}

void solve(){
    vector<long long> candi;
    long long _min = M * N / gcd(M,N) ;

    // M의 후보 구하기
    for(int i=x; i<= _min; i+=M){
        if(i <= _min){
            if((i%N==0 && N==y) || (i%N == y)){
                cout << i << "\n";
                return;
            }
        }
    }

    cout << -1 << "\n";
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