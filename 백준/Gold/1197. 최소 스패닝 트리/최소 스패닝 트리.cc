//
// Created by yooki on 2024/10/02.
//
#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int V,E;
vector<int> parent;
struct cmp {
    bool operator()(tuple<int,int,int> t1, tuple<int,int,int> t2){
        return get<2>(t1) > get<2>(t2);
    }
};

priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>, cmp> pq;
void init(){
    cin >> V >> E;

    for(int i=0; i<E; i++){
        int n1,n2,cost;
        cin >> n1 >> n2 >> cost;

        pq.push(make_tuple(n1,n2,cost));
    }

    parent.resize(V+1,0);
    for(int i=0; i<V; i++){
        parent[i+1] = i+1;
    }
}

int findParent(int node){
    if(parent[node] == node)
        return node;
    return findParent(parent[node]);
}

void makeUnion(int node1, int node2){
    node1 = findParent(node1);
    node2 = findParent(node2);

    if(node1 < node2)
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
    int cnt = 0, result = 0;
    while(!pq.empty()){
        tuple<int,int,int> t = pq.top(); pq.pop();
        int n1 = get<0>(t), n2 =  get<1>(t);

        if(!isCycle(n1,n2)){
            makeUnion(n1,n2);
            cnt+=1;
            result += get<2>(t);
        }

        if(cnt==V-1)
            break;
    }

    cout << result << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    init();
    solve();
    return 0;
}