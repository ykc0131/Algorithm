//
// Created by yooki on 2024/02/27.
//
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int N;
vector<vector<int>> vec;

void init(){
    cin >> N;
    vec.clear();
    vec.resize(N+1,vector<int>(N+1,0));

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> vec[i][j];
        }
    }
}

vector<vector<bool>> visited;
int dx[] = {1,0};
int dy[] = {0,1};
tuple<int,int> dfs(int y, int x, tuple<int,int,int> info){
    visited[y][x] = true;

    int n0=0, n1=0;
    int edge = get<2>(info);
    for(int i=0; i<2; i++){
        int _y = y+dy[i];
        int _x = x+dx[i];

        if(_y < get<0>(info) || _x < get<1>(info) || _y >= get<0>(info)+edge || _x >= get<1>(info)+edge)
            continue;

        if(!visited[_y][_x]){
            tuple<int, int> t = dfs(_y, _x, info);
            n0 += get<0>(t);
            n1 += get<1>(t);
        }
    }

    if(vec[y][x]==0)
        return {n0+1,n1};
    else
        return {n0,n1+1};
}


int blue = 0, white = 0;
void square(int startY, int startX, int edge){
    visited.clear();
    visited.resize(N,vector<bool>(N,false));
    tuple<int,int> result = dfs(startY, startX, {startY, startX, edge});
    if(get<0>(result)==0 ){
        blue++; return;
    }
    else if(get<1>(result)==0){
        white++; return;
    }

    int mid = edge/2;
    square(startY, startX, mid);
    square(startY, startX+mid, mid);
    square(startY+mid, startX, mid);
    square(startY+mid, startX+mid, mid);
}

void solve(){
    square(0,0,N);
    cout << white << endl << blue << endl;
}

int main(){
    init();
    solve();
    return 0;
}