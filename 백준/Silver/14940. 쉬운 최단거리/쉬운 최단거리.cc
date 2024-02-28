//
// Created by yooki on 2024/02/28.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,m;
pair<int,int> start;
vector<vector<int>> vec;
int dx[] = {1,0, -1, 0};
int dy[] = {0,1,0,-1};

void init(){
    cin >> n >> m;
    vec.clear();
    vec.resize(n+1, vector<int>(m+1,0));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> vec[i][j];
            if(vec[i][j]==2){
                start = {i,j};
            }
        }
    }
}

vector<vector<bool>> visited;
vector<vector<int>> result;
void bfs(){
    queue<pair<int,int>> q;
    q.push(start);
    visited[start.first][start.second] = true;

    while(!q.empty()){
        pair<int,int> cur = q.front(); q.pop();

        for(int i=0; i<4; i++){
            int _y = cur.first + dy[i];
            int _x = cur.second + dx[i];

            if(_y < 0 || _x < 0 || _y >= n || _x >= m)
                continue;

            if(!visited[_y][_x] && vec[_y][_x]==1){
                result[_y][_x] = result[cur.first][cur.second] + 1;
                visited[_y][_x] = true;
                q.push({_y,_x});
            }
        }
    }
}

void solve(){
    visited.clear();
    result.clear();
    visited.resize(n,vector<bool>(m,false));
    result.resize(n,vector<int>(m,0));
    bfs();

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(result[i][j]==0 && vec[i][j]==1)
                cout << -1 << " ";
            else
                cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    init();
    solve();
    return 0;
}