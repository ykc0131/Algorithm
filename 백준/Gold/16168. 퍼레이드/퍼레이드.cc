//
// Created by yooki on 2024/07/11.
//
#include <iostream>
#include <vector>

using namespace std;

int V,E;
vector<vector<int>> adl;
vector<vector<int>> adm;

void init(){
    cin >> V >> E;

    adl.resize(V+1);
    adm.resize(V+1, vector<int>(V+1,0));

    for(int i=0; i<E; i++){
        int v1,v2;
        cin >> v1 >> v2;

        adl[v1].push_back(v2);
        adl[v2].push_back(v1);
        adm[v1][v2] = 1;
        adm[v2][v1] = 1;
    }
}

bool result = false;
void dfs(int node, int idx, int edgeCnt){
    if(edgeCnt==E){
        result = true;
        return;
    }

    for(int next : adl[node]){
        if(adm[node][next] == idx || adm[next][node] == idx) continue;
        adm[node][next] = adm[next][node] = idx;
        dfs(next, idx, edgeCnt+1);
    }
}

void solve(){
    for(int i=1; i<V+1; i++){
        dfs(i, i, 0);
    }

    if(result)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main(){
    init();
    solve();
    return 0;
}