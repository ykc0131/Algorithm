//
// Created by yooki on 2024/01/27.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int K,N;
vector<long long> vec;

void init(){
    cin >> K >> N;
    vec.clear();
    vec.resize(K,0);

    for(int i=0; i<K; i++)
        cin >> vec[i];
    sort(vec.begin(), vec.end());
}

void solve(){
    long long start = 1, end = vec[K-1], result = 0;
    while(start<=end){
        long long mid = (start+end)/2;
        int sum = 0;

        for(int i=0; i<K; i++)
            sum += vec[i]/mid;

        if(sum >= N){
            start = mid + 1;
            result = result > mid ? result : mid;
        }
        else if(sum < N)
            end = mid - 1;
    }
    cout << result << "\n";
}


int main(){
    init();
    solve();
    return 0;
}
