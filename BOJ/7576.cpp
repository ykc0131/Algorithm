//
// Created by yooki on 2024/01/02.
//
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int M,N, total=0;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
vector<vector<int>> vec;
queue<tuple<int,int,int>> q;

void init(){
    cin >> M >> N;
    vec.clear();
    vec.resize(N,vector<int>(M,0));
    for(int i=0; i<N ; i++){
        for(int j=0; j<M; j++){
            cin >> vec[i][j];
            if(vec[i][j]==1){
                q.push(make_tuple(i,j,1));
            }
            total += (vec[i][j]==0 ? 1 : 0);
        }
    }
}

void solve(){
    int max = 1;
    while(!q.empty()){
        tuple<int,int,int> cur = q.front(); q.pop();

        for(int i=0; i<4;i++){
            int _y = get<0>(cur) + dy[i];
            int _x = get<1>(cur) + dx[i];
            int value = get<2>(cur) + 1;

            if(_y < 0 || _x < 0 || _y >= N || _x >= M)
                continue;
            if(vec[_y][_x]==-1)
                continue;
            else if(vec[_y][_x]==0){
                vec[_y][_x] = value;
                total--;
                q.push(make_tuple(_y,_x,value));
                max = value > max ? value : max;
            }
        }
    }
    if(total!=0)
        cout << -1 << "\n";
    else
        cout << max-1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    solve();
    return 0;
}