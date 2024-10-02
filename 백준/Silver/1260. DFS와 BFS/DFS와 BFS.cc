//
// Created by yooki on 2024/10/02.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int N,M,V;
vector<vector<int>> vec;
void init(){
    cin >> N >> M >> V;

    vec.resize(N+1);
    for(int i=0; i<M; i++){
        int n,v;
        cin >> n >> v;
        vec[n].push_back(v);
        vec[v].push_back(n);
    }

    for(int i=1; i<N+1; i++){
        sort(vec[i].begin(), vec[i].end());
    }
}

pair<string,string> result;
vector<bool> visited;
void bfs(){
    queue<int> q;
    q.push(V);

    while(!q.empty()){
        int cur = q.front(); q.pop();

        if(visited[cur])
            continue;
        visited[cur] = true;
        result.second += (to_string(cur) + " ");

        for(int i=0; i< vec[cur].size(); i++){
            int next = vec[cur][i];

            if(!visited[next]){
                q.push(next);
            }
        }
    }
}


void dfs(int n){
    if(visited[n])
        return;
    visited[n] = true;
    result.first += (to_string(n) + " ");

    for(int i=0; i<vec[n].size(); i++){
        int next = vec[n][i];

        if(!visited[next]){
            dfs(next);
        }
    }
}

void clear(){
    visited.clear();
    visited.resize(N+1, false);
}

void solve(){
    clear();
    dfs(V);

    clear();
    bfs();

    cout << result.first << "\n" << result.second << "\n";
}

int main(){
    init();
    solve();
    return 0;
}