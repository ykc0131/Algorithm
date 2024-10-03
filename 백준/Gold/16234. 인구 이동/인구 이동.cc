//
// Created by yooki on 2024/10/03.
//
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int N, L, R;
vector<vector<int>> vec;
void init(){
    cin >> N >> L >> R;

    vec.clear();
    vec.resize(N);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int n;
            cin >> n;
            vec[i].push_back(n);
        }
    }
}

vector<vector<bool>> visited;
void clear(){
    visited.clear();
    visited.resize(N, vector<bool>(N,false));
}

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int bfs(pair<int,int> p){
    int cnt = 0, total = 0;
    queue<pair<int,int>> q;
    vector<pair<int,int>> cordi;
    q.push(p);

    while(!q.empty()){
        pair<int,int> cur = q.front(); q.pop();
        int y = cur.first, x = cur.second, cost = vec[y][x];
        if(visited[y][x])
            continue;
        visited[y][x] = true;
        cordi.push_back(cur);
        total += cost;
        cnt+=1;

        for(int i=0; i<4; i++){
            int _y = y + dy[i];
            int _x = x + dx[i];

            if(_y < 0 || _x < 0 || _y >= N || _x >= N)
                continue;

            int _cost = vec[_y][_x];
            if(!visited[_y][_x] && (abs(cost-_cost) >= L && abs(cost-_cost) <= R)){
                q.push({_y,_x});
            }
        }
    }

    if(cnt!=1) {
        int people = total/cnt;
        for(auto c : cordi){
            vec[c.first][c.second] = people;
        }
    }
    return cnt-1;
}

void solve(){
    int result = 0;
    while(true){
        clear();
        int cnt = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(!visited[i][j]){
                    cnt += bfs({i,j});
                }
            }
        }

        if(cnt==0)
            break;
        else
            result++;
    }

    cout << result << "\n";
}

int main(){
    init();
    solve();
    return 0;
}