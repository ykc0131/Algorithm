//
// Created by yooki on 2024/01/06.
//
#include <iostream>
#include <queue>

using namespace std;

int N;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

void init(){
    cin >> N;
    for(int i=0; i<N; i++){
        int x,y;
        cin >> x >> y;
        pq.push({x,0});
        pq.push({y,1});
    }
}

void solve(){
    int cnt = 0, len = 0, start = -1;
    while(!pq.empty()){
        pair<int,int> p = pq.top(); pq.pop();
        if(p.second==0){
            cnt++;
            if(start==-1)
                start = p.first;
        }
        else if(p.second==1)
            cnt--;
        if(cnt==0){
            len += p.first - start;
            start = -1;
        }
    }
    cout << len << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.ignore(false);
    init();
    solve();
    return 0;
}