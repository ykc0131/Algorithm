#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<vector<int>> vec;
void input(vector<vector<int>> computers){
    N = computers.size();
    vec.clear();
    vec.resize(N);
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(computers[i][j] == 1 && i!=j){
                vec[i].push_back(j);
                vec[j].push_back(i);
            }
        }
    }
}

vector<int> visited;
void clear(){
    visited.clear();
    visited.resize(N, false);
}

void bfs(int n){
    queue<int> q;
    q.push(n);
    
    while(!q.empty()){
        int cur = q.front(); q.pop();
        
        if(visited[cur])
            continue;
        visited[cur] = true;
        
        for(auto v : vec[cur]){
            if(!visited[v]){
                q.push(v);
            }
        }
        
    }
}

int cnt=0;
void solve(){
    clear();
    for(int i=0; i<N; i++){
        if(!visited[i]){
            bfs(i);
            cnt++;
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    input(computers);
    solve();

    return cnt;
}