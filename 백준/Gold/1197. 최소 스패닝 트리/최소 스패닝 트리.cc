//
// Created by yooki on 2024/02/23.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int V,E;
vector<tuple<int,int,int>> edges;
vector<int> parent;

bool cmp(tuple<int,int,int> a, tuple<int,int,int> b){
    return get<2>(a) < get<2>(b);
}

void init(){
    cin >> V >> E;
    edges.clear();
    parent.clear();
    parent.resize(V+1,0);

    for(int i=0; i<E; i++){
        int u,v,cost;
        cin >> u >> v >> cost;
        edges.push_back({u,v,cost});
    }

    //parent 배열 설정
    for(int i=1; i<V+1; i++){
        parent[i] = i;
    }

    sort(edges.begin(),edges.end(),cmp);
}

int findParent(int node){
    if(parent[node]==node)
        return node;
    return findParent(parent[node]);
}

void unionNode(int node1, int node2){
    node1 = findParent(node1);
    node2 = findParent(node2);

    if(node1<node2)
        parent[node2] = node1;
    else
        parent[node1] = node2;
}

bool isCycle(int node1, int node2){
    node1 = findParent(node1);
    node2 = findParent(node2);
    if(node1==node2)
        return true;
    return false;
}

void solve(){
    long long result = 0;
    for(int i=0; i<edges.size(); i++){
        int node1 = get<0>(edges[i]);
        int node2 = get<1>(edges[i]);
        if(!isCycle(node1,node2)){
            unionNode(node1,node2);
            result += get<2>(edges[i]);
        }
    }
    cout << result << endl;
}

int main(){
    init();
    solve();
    return 0;
}