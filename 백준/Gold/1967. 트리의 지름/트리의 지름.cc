//
// Created by yooki on 2024/02/16.
//
#include <iostream>
#include <vector>
#define INF 100000001

using namespace std;

int n;
vector<vector<pair<int,int>>> tree;

void init(){
    cin >> n;
    tree.resize(n+1);

    for(int i=0; i<n-1; i++){
        int u,v,cost;
        cin >> u >> v >> cost;

        tree[u].push_back({v,cost});
        tree[v].push_back({u,cost});
    }
}

vector<bool> visited;
vector<int> dist;
void dfs(int x, int sum){
    if(visited[x])
        return;
    visited[x] = true;

    for(int i=0; i<tree[x].size(); i++){
        int next = tree[x][i].first;
        int nextCost = tree[x][i].second;

        if(!visited[next]){
            dist[next] = sum + nextCost;
            dfs(next, sum + nextCost);
        }
    }
}

pair<int,int> findLargest(int x){
    visited.clear();
    dist.clear();
    visited.resize(n+1,false);
    dist.resize(n+1,INF);
    dist[x] = 0;

    dfs(x,0);

    int maxD = 0, maxV = 0;
    for(int i=1; i<n+1; i++){
        if(maxD < dist[i]){
            maxD = dist[i];
            maxV = i;
        }
    }

    return {maxV,maxD};
}

void solve(){
    pair<int,int> from1Vertex = findLargest(1);

    pair<int,int> result = findLargest(from1Vertex.first);

    if(result.second==INF)
        result.second = 0;
    cout << result.second << "\n";
}

int  main(){
    init();
    solve();
    return 0;
}