#include <iostream>
#include<vector>
#include <queue>
using namespace std;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int N,M;
vector<vector<int>> vec;
vector<vector<int>> dist;
void init(vector<vector<int>> maps){
    vec = maps;
    N = vec.size();
    M = vec[0].size();
    
    dist.resize(N,vector<int>(M,N*M+1));
}

vector<vector<bool>> visited;
void bfs(){
    queue<pair<int,int>> q;
    q.push({0,0});
    dist[0][0] = 1;
    
    while(!q.empty()){
        pair<int,int> cur = q.front(); q.pop();
        int y = cur.first;
        int x = cur.second;
        
        if(visited[y][x])
            continue;
        visited[y][x] = true;
        
        if(y==N-1 && x==M-1)
            break;
        
        for(int i=0; i<4; i++){
            int _y = y + dy[i];
            int _x = x + dx[i];
            
            if(_y < 0 || _x < 0 || _y >= N || _x >= M)
                continue;
            
            if(!visited[_y][_x] && vec[_y][_x] == 1){
                q.push({_y,_x});
                dist[_y][_x] = min(dist[_y][_x], dist[y][x] + 1);   
            }
        }
    }
}

void clear(){
    visited.clear();
    visited.resize(N+1, vector<bool>(M+1, false));
}

void solve(){
    clear();
    bfs();
}

int solution(vector<vector<int> > maps)
{
    init(maps);
    solve();
    
    return (dist[N-1][M-1] != N*M+1 ? dist[N-1][M-1] : -1);
}