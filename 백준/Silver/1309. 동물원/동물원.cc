//
// Created by yooki on 2024/10/03.
//
#include <iostream>
#include <queue>
#include <tuple>
#define NUM 9901

using namespace std;

int N;
void init(){
    cin >> N;
    N-=1;
}

void solve(){
    queue<tuple<int,int,int>> q;
    q.push({1,1,1});

    while(N--){
        tuple<int,int,int> cur = q.front(); q.pop();

        int l = get<1>(cur) + get<2>(cur);
        int r = get<0>(cur) + get<2>(cur);
        int t = get<0>(cur) + get<1>(cur) + get<2>(cur);
        q.push({l%NUM,r%NUM,t%NUM});
    }

    tuple<int,int,int> cur = q.front(); q.pop();
    cout << (get<0>(cur) + get<1>(cur) + get<2>(cur))%NUM << "\n";
}

int main(){
    init();
    solve();
    return 0;
}