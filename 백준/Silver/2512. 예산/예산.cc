//
// Created by yooki on 2024/01/24.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long long N,M,avgValue;
priority_queue<long long,vector<long long>,greater<long long>> pq;

void init(){
    cin >> N;

    for(int i=0; i<N; i++){
        long long n;
        cin >> n;
        pq.push(n);
    }

    cin >> M;
    avgValue = M/N;
}

void solve(){
    long long result = 0, preN = 0;
    while(!pq.empty()){
        long long curN = pq.top();
        preN = curN;
        if(curN > avgValue && result+curN*pq.size() >= M){
            M-=result;
            M/=pq.size();
            cout << M << "\n";
            return;
        }
        else
            result+=curN;
        pq.pop();
    }
    cout << preN << "\n";
}


int main(){
    init();
    solve();
    return 0;
}