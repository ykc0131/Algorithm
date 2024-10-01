//
// Created by yooki on 2024/10/01.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N,M;
vector<vector<int>> grid;
vector<pair<int,int>> blank;
vector<pair<int,int>> virus;
void init(){
    cin >> N >> M;

    grid.clear();
    grid.resize(N,vector<int>(M,0));
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> grid[i][j];
            if(grid[i][j]==0)
                blank.push_back({i,j});
            if(grid[i][j]==2)
                virus.push_back({i,j});
        }
    }
}

int result = 0;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
void check(){
    vector<vector<int>> tmp;
    tmp.assign(grid.size(), vector<int>(grid.size()));
    copy(grid.begin(), grid.end(), tmp.begin());

    queue<pair<int,int>> q;
    vector<vector<bool>> visited(N,vector<bool>(M,false));
    for(pair<int,int> p : virus){
        q.push(p);
    }

    while(!q.empty()){
        pair<int,int> cur = q.front(); q.pop();

        if(visited[cur.first][cur.second])
            continue;
        visited[cur.first][cur.second] = true;

        for(int i=0; i<4; i++){
            int _y = cur.first + dy[i];
            int _x = cur.second + dx[i];

            if(_y < 0 || _x < 0 || _y >= N || _x >= M)
                continue;

            if(!visited[_y][_x] && tmp[_y][_x]==0){
                q.push({_y,_x});
            }
        }
    }

    int cnt = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(!visited[i][j] && tmp[i][j] == 0)
                cnt++;
        }
    }

    result = max(result, cnt);
}

void makeWall(int idx, int cnt){
    if(cnt==3){
        check();
        return;
    }

    if(idx>=blank.size())
        return;

    for(int i=idx; i<blank.size(); i++){
        pair<int,int> next = blank[i];
        grid[next.first][next.second] = 1;
        makeWall(i+1, cnt+1);
        grid[next.first][next.second] = 0;
    }


}

void solve(){
    makeWall(0,0);
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