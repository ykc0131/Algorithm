//
// Created by yooki on 2024/03/07.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int M,N,K;
vector<vector<int>> cabbage;
void init(){
    cin >> M >> N >> K;

    cabbage.clear();
    cabbage.resize(M,vector<int>(N,0));
    for(int i=0; i<K; i++){
        int n,m;
        cin >> n >> m;
        cabbage[n][m] = 1;
    }
}

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
void bfs(int y, int x){
     queue<pair<int,int>> q;
     q.push({y,x});
     cabbage[y][x]=0;

     while(!q.empty()){
         int curY = q.front().first;
         int curX = q.front().second; q.pop();

         for(int i=0; i<4; i++){
             int _y = curY + dy[i];
             int _x = curX + dx[i];

             if(_y<0 || _x<0 || _y>=M || _x>=N)
                 continue;
             if(cabbage[_y][_x]){
                 q.push({_y,_x});
                 cabbage[_y][_x]=0;
             }
         }
     }
}

void solve(){
    int cnt = 0;
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            if(cabbage[i][j]){
                bfs(i,j);
                cnt ++;
            }
        }
    }
    cout << cnt << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        init();
        solve();
    }
    return 0;
}