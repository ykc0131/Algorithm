//
// Created by yooki on 2024/01/25.
//
//이진탐색
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M;
vector<int> vec;

void init(){
    cin >> N;
    vec.clear();
    vec.resize(N,0);

    for(int i=0; i<N; i++){
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    cin >> M;
}

void solve(){
    int start=0, end=vec[N-1], result, sum;
    while(start<=end){
        sum=0;
        int mid = (start+end)/2;

        for(int i=0; i<N; i++){
            sum+=min(vec[i],mid);
        }

        if(sum<=M){
            result = mid;
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    cout << result << "\n";
}

int main(){
    init();
    solve();
    return 0;
}