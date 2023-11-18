//
// Created by yooki on 2023/11/18.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct cmp{
    bool operator()(pair<long long,int> a, pair<long long,int> b){
        return a.first < b.first;
    }
};

int N;
vector<vector<int>> v;
vector<int> column;
priority_queue<pair<long long,int>, vector<pair<long long,int>>, cmp > pq;

void init(){
    cin >> N;
    v.clear();
    v.resize(N,vector<int>(N,0));
    column.clear();
    column.resize(N,N-1);
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> v[i][j];
            if(i == N-1)
                pq.push({v[i][j],j});
        }
    }
}

void solve(){
    while(--N){
        int curX = pq.top().second; pq.pop();

        if(column[curX]-1 < 0)
            continue;
        column[curX] -= 1;
        pq.push({v[column[curX]][curX],curX});
    }
    cout << pq.top().first << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    init();
    solve();
    return 0;
}