//
// Created by yooki on 2024/01/26.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
long long M;
vector<long long> vec;

void init(){
    cin >> N >> M;
    vec.clear();
    vec.resize(N,0);
    for(int i=0; i<N; i++){
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
}

void solve(){
    long long start = 0, end = vec[N-1],result;

    while(start<=end){
        long long sum = 0;
        long long mid = (start+end)/2;

        for(int i=0; i<N; i++){
            long long sub = vec[i]-mid;
            sum += (sub > 0 ? sub : 0);
        }

        if(sum >= M){
            start = mid+1;
            result = mid;
        }
        else
            end = mid-1;
    }

    cout << result << "\n";
}


int main(){
    init();
    solve();
    return 0;
}