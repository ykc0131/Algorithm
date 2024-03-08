//
// Created by yooki on 2024/03/08.
//
#include <iostream>
#include <vector>

using namespace std;

int N,M;
vector<vector<int>> vec;
void init(){
    cin >> N >> M;
    vec.clear();
    vec.resize(N+1);

    for(int i=0; i<M; i++){
        int u,v;
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
}

vector<bool> visited;
void dfs(int n){
    visited[n] = true;

    for(int i=0; i<vec[n].size(); i++){
        int next = vec[n][i];
        if(!visited[next]){
            dfs(next);
        }
    }
}

void solve(){
    visited.clear();
    visited.resize(N+1,false);

    int cnt = 0;
    for(int i=1; i<N+1; i++){
        if(!visited[i]){
            dfs(i);
            cnt++;
        }
    }
    cout << cnt << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
    return 0;
}