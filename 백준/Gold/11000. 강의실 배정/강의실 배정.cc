//
// Created by yooki on 2024/03/09.
//
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
vector<pair<int,int>> vec;

struct cmpQ{
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.second > b.second;
    }
};
bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

void init(){
    cin >> N;
    for(int i=0; i<N; i++){
        int n,m;
        cin >> n >> m;
        vec.push_back({n,m});
    }
    sort(vec.begin(), vec.end(), cmp);
}

priority_queue<pair<int,int>,vector<pair<int,int>>, cmpQ> q;
void solve(){
    for(auto p : vec){
        if(!q.empty()){
            pair<int,int> qFront = q.top();
            if(qFront.second <= p.first)
                q.pop();
        }
        q.push(p);
    }

    cout << q.size() << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
    return 0;
}

//1차 시도 : 실패