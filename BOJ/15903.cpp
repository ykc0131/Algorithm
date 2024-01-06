//
// Created by yooki on 2024/01/06.
//
#include <iostream>
#include <queue>

using namespace std;

int n,m;
priority_queue<long long, vector<long long>, greater<long long>> pq;

void init(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        pq.push(num);
    }
}

void solve(){
    while(m--){
        long long n1 = pq.top(); pq.pop();
        long long n2 = pq.top(); pq.pop();

        pq.push(n1+n2);
        pq.push(n1+n2);
    }

    long long sum = 0;
    while(!pq.empty()){
        sum += pq.top(); pq.pop();
    }
    cout << sum << "\n";
}

int main(){
    init();
    solve();
    return 0;
}