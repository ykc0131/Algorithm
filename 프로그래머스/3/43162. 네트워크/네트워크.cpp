#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> parent;
void init(int N){
    parent.resize(N, 0);
    for(int i=0; i<N; i++){
        parent[i] = i;
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

int solution(int n, vector<vector<int>> computers) {
    int size = computers.size();
    init(size);
    
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(computers[i][j]==1){
                makeUnion(i,j);
            }
        }
    }
    
    
    map<int,int> m;
    for(int i=0; i<size; i++){
        parent[i] = findParent(i);
        m[parent[i]] = 1;
    }
    
    return m.size();
}