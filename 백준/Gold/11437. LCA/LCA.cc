//
// Created by yooki on 2024/02/19.
//
#include <iostream>
#include <vector>
#define MAX 20

using namespace std;

int N,M,root;
vector<vector<int>> graph;
vector<pair<int,int>> pairs;
vector<vector<int>> parent;
vector<int> depth;

void init(){
    cin >> N;
    root = 1;
    graph.clear();
    parent.clear();
    depth.clear();
    graph.resize(N+1);
    parent.resize(N+1,vector<int>(MAX,-1));
    depth.resize(N+1,-1);

    for(int i=0; i<N-1; i++){
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cin >> M;
    for(int i=0; i<M; i++){
        int u,v;
        cin >> u >> v;
        pairs.push_back({u,v});
    }

}

vector<bool> visited;
void dfs(int x){
    if(visited[x])
        return;
    visited[x] = true;
    for(int i=0; i<graph[x].size(); i++){
        int next = graph[x][i];

        if(!visited[next] && depth[next]==-1){
            parent[next][0] = x;
            depth[next] = depth[x]+1;
            dfs(next);
        }
    }
}

//parent 배열 채우기
void setParent(){
    for(int j=0; j<(int)MAX-1; j++){
        for(int i=1; i<N+1; i++){
            if(parent[i][j]!=-1){
                parent[i][j+1] = parent[parent[i][j]][j]; //공식
            }
        }
    }
}

//각 정점의 depth 찾기
void setDepth(){
    visited.clear();
    visited.resize(N+1,false);
    depth[root] = 0;
    dfs(root);
}

int lca(int u, int v){
    //u와 v 깊이 같게 만들기
    if(depth[u] < depth[v])
        swap(u,v);
    if(depth[u] > depth[v]) { // 정점 u의 깊이가 정점 v보다 깊을 때, parent[u]로 대체
        int diff = depth[u]-depth[v];
        for(int j=0; diff!=0; j++){
            if( diff%2 != 0 ){
                u = parent[u][j];
            }
            diff/=2;
        }
    }

    //깊이를 똑같이 유지 + 공통 부모가 나올 때까지 정점 바꾸기
    if(u!=v){
        // 위에서부터 순차적으로 부모가 맞는지 찾아본다.
        // 맞지 않는 순간이 공통 부모 바로 전단계!
        for(int i=(int)MAX-1; i>=0; i--){
            if((parent[u][i] != -1) && (parent[u][i] != parent[v][i])){
                u = parent[u][i];
                v = parent[v][i];
            }
        }
        //parent[u][i]!=parent[v][i] 위의 값부터 값이 같을 가능성 up.
        u = parent[u][0];
    }
    return u;
}

void solve(){
    setDepth();
    setParent();
    vector<int> ans;
    for(int i=0; i<M; i++){
        ans.push_back(lca(pairs[i].first, pairs[i].second));
    }

    for(int i=0; i<M; i++){
        cout << ans[i] << "\n";
    }
}

int main(){
    init();
    solve();
    return 0;
}
