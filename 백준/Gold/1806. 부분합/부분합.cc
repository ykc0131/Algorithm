//
// Created by yooki on 2024/07/10.
//
#include <iostream>
#include <vector>
#include <limits.h>

#define INF INT_MAX

using namespace std;

long long N,S;
vector<long long> vec;

void init(){
    cin >> N >> S;

    vec.push_back(0);
    for(int i=1; i<N+1; i++){
        int n;
        cin >> n;
        vec.push_back(n);
        vec[i] += vec[i-1];
    }
}

void solve(){
    long long l=1, r=1, minL=INF;

    if(vec[N]<S){
        cout << 0 << "\n";
        return;
    }

    while(l <= r && r <= N ) {
        if(vec[r] - vec[l-1] >= S) {
            minL = min(minL, r - l + 1);
            l++;
        }
        else
            r++;
    }
    cout << minL << "\n";
}

int main(){
    init();
    solve();
    return 0;
}