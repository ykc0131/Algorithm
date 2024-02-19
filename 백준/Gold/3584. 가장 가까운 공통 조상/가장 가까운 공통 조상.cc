//
// Created by yooki on 2024/02/17.
//
#include <iostream>
#include <vector>
#define MAX 16

using namespace std;

int T;
int N,root,U,V;
vector<vector<int>> graph;
vector<vector<int>> parent;
vector<int> depth;

void init(){
    cin >> N;
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
        parent[v][0] = u;
    }
    cin >> U >> V;

}

//트리이기 때문에 이미 방문한 정점인지 확인할 필요가 없다. -> visit 변수 필요없음.
void dfs(int x){
    for(int i=0; i<graph[x].size(); i++){
        int next = graph[x][i];

        if(depth[next]==-1){
            depth[next] = depth[x]+1;
            dfs(next);
        }
    }
}

//루트 노드 찾기
void findRootNode(){
    for(int i=1; i<N+1; i++){
        if(parent[i][0] == -1){
            root = i;
            return;
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
    depth[root] = 0;
    dfs(root);
}

int lca(){
    int u=U, v=V;
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
    findRootNode();
    setDepth();
    setParent();
    int ans = lca();
    cout << ans << "\n";
}

int main(){
    cin >> T;
    while(T--){
        init();
        solve();
    }
    return 0;
}