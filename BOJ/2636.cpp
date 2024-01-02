//
// Created by yooki on 2024/01/02.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int M,N,totalCnt;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
vector<vector<int>> vec;
vector<vector<int>> readyToD;

void init(){
    cin >> M >> N;
    totalCnt=0;
    vec.clear();
    readyToD.clear();
    vec.resize(M, vector<int>(N,0));
    readyToD.resize(M,vector<int>(N,0));
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            cin >> vec[i][j];
            if(vec[i][j]==1)
                totalCnt+=1;
        }
    }
}

int timeCnt=0;
int bfs(){
    int cnt=0;
    vector<vector<bool>> visited(M,vector<bool>(N,false));
    queue<pair<int,int>> q;
    q.push(make_pair(timeCnt, timeCnt));
    visited[timeCnt][timeCnt] = true;

    while(!q.empty()){
        pair<int,int> cur = q.front(); q.pop();

        for(int i=0; i<4;i++){
            int _y = cur.first + dy[i];
            int _x = cur.second + dx[i];

            if(_y < timeCnt || _x < timeCnt || _y >= M - timeCnt || _x >= N - timeCnt)
                continue;
            if(!visited[_y][_x]){
                if(vec[_y][_x]==0)
                    q.push(make_pair(_y,_x));
                else if(vec[_y][_x]==1){
                    cnt+=1;
                    vec[_y][_x] = 0;
                }
            }
            visited[_y][_x] = true;
        }
    }
    return cnt;
}

void solve(){
    int cnt = 0;
    //치즈 구멍 부분을 어떻게 처리해야하나..
    while(totalCnt>0){
        cnt =  bfs();
        totalCnt -= cnt;
        timeCnt++;
    }
    cout << timeCnt << "\n";
    cout << cnt << "\n";
}


int main(){
    init();
    solve();
    return 0;
}