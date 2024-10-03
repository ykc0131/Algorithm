//
// Created by yooki on 2024/10/03.
//
#include <iostream>
#include <vector>
#include <queue>
#define INF 2000000

using namespace std;

int V,E,K;
vector<vector<pair<int,int>>> vec;
void init(){
    cin >> V >> E >> K;

    vec.clear();
    vec.resize(V+1);
    for(int i=0; i<E; i++){
        int u,v,w;
        cin >> u >> v >> w;

        vec[u].push_back({v,w});
    }
}

struct cmp {
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.second > b.second;
    }
};

void dij(){
    vector<int> dist(V+1, INF);
    vector<bool> visited(V+1, false);

    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    dist[K] = 0;
    pq.push({K,0});

    int cnt = 0;
    while(!pq.empty()){
        pair<int,int> cur = pq.top(); pq.pop();
        int curN = cur.first;
        int cost = cur.second;

        if(visited[curN])
            continue;
        visited[curN] = true;
        cnt += 1;
        if(cnt==V)
            break;

        for(auto v : vec[cur.first]){
            int next = v.first;
            int _cost = cost + v.second;

            if(!visited[next] && dist[next] > _cost){
                dist[next] = _cost;
                pq.push({next, _cost});
            }
        }
    }

    for(int i=1; i<V+1; i++){
        if(dist[i]==INF)
            cout << "INF\n";
        else
            cout << dist[i] << "\n";
    }
}

void solve(){
    dij();
}

int main(){
    init();
    solve();
    return 0;
}