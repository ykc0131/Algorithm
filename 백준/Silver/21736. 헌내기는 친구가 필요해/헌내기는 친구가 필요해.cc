//
// Created by yooki on 2024/07/19.
//
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int N,M;
int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};
vector<vector<int>> vec;
vector<vector<bool>> visited;
pair<int,int> me;

void init(){
    cin >> N >> M;

    vec.resize(N,vector<int>(M,0));
    visited.resize(N,vector<bool>(M,false));
    for(int i=0; i<N; i++){
        string s;
        cin >> s;
        for(int j=0; j<M; j++){
            if(s[j]=='O')
                vec[i][j] = 0;
            else if(s[j]=='X')
                vec[i][j] = 1;
            else if(s[j]=='I'){
                vec[i][j] = 2;
                me = {i,j};
            }
            else if(s[j]=='P')
                vec[i][j]=3;
        }
    }
}

int result = 0;
void bfs(){
    priority_queue<pair<int,int>> pq;

    pq.push({me.first, me.second});
    while(!pq.empty()){
        pair<int,int> cur = pq.top(); pq.pop();
        if(visited[cur.first][cur.second])
            continue;
        visited[cur.first][cur.second] = true;
        if(vec[cur.first][cur.second]==3)
            result++;

        for(int i=0; i<4; i++){
            int _y = cur.first + dy[i];
            int _x = cur.second + dx[i];

            if(_y < 0 || _x < 0 || _y >= N || _x >= M)
                continue;
            if(!visited[_y][_x] && vec[_y][_x]!=1){
                pq.push({_y,_x});
            }
        }
    }
}

void solve(){
    bfs();

    if(result==0)
        cout << "TT" << endl;
    else
        cout << result << "\n";
}

int main(){
    init();
    solve();
    return 0;
}