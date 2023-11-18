//
// Created by yooki on 2023/11/18.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> pq;
vector<int> v;

void init(){
    cin >> N;
}

void solve(){
    while(N--){
        int x;
        cin >> x;

        if(x == 0){
            int n = 0;
            if(!pq.empty()){
                n = pq.top(); pq.pop();
            }
            v.push_back(n);
            continue;
        }
        pq.push(x);
    }
}

void result(){
    for(int _v : v){
        cout << _v << "\n";
    }
}

int main() {
    init();
    solve();
    result();

    return 0;
}
