//
// Created by yookim on 2024/07/10.
//
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

long long N, S;
vector<long long> vec;

void init(){
    cin >> N >> S;

    vec.push_back(0);
    for(int i = 1; i <= N; i++){
        long long n;
        cin >> n;
        vec.push_back(n);
        vec[i] += vec[i - 1];
    }
}

void solve(){
    long long l = 0, r = 0;
    long long minL = numeric_limits<long long>::max();

    while(r <= N){
        if(vec[r] - vec[l] >= S){
            minL = min(minL, r - l);
            l++;
        } else {
            r++;
        }
    }

    if(minL == numeric_limits<long long>::max()){
        cout << 0 << "\n";
    } else {
        cout << minL << "\n";
    }
}

int main(){
    init();
    solve();
    return 0;
}
