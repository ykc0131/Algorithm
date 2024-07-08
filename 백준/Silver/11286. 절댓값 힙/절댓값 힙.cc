//
// Created by yooki on 2024/07/08.
//
#include <iostream>
#include <queue>

using namespace std;

struct cmp{
    bool operator()(int a, int b){
        if(abs(a) == abs(b))
            return a > b;
        return abs(a) > abs(b);
    }
};

int N;
void init(){
    cin >> N;
}

priority_queue<int,vector<int>, cmp> pq;
void solve(){
    while(N--){
        int x;
        cin >> x;

        if(x==0){
            if(!pq.empty()){
                cout << pq.top() << "\n"; pq.pop();
            }
            else
                cout << 0 << "\n";
        }
        else
            pq.push(x);
    }
}

int main(){
    init();
    solve();
    return 0;
}
