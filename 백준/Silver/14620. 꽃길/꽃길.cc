#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
vector<vector<int>> vec;
vector<vector<int>> cost;
vector<vector<bool>> visited;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

void init(){
    cin >> N;
    vec.resize(N, vector<int>(N,0));
    cost.resize(N,vector<int>(N,0));
    visited.resize(N,vector<bool>(N,false));

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> vec[i][j];
        }
    }

    for(int i=1; i<N-1; i++){
        for(int j=1; j<N-1; j++){
            cost[i][j] = vec[i][j];
            for(int k=0; k<4; k++){
                int _y = i + dy[k];
                int _x = j + dx[k];

                cost[i][j] += vec[_y][_x];
            }
        }
    }
}

int minResult = 2000000;
vector<pair<int,int>> flowerCordi;
bool checkFlower(int y, int x){
    for(pair<int,int> p : flowerCordi){
        int _y = abs(p.first-y);
        int _x = abs(p.second-x);

        if(_y + _x <= 2)
            return false;
    }
    return true;
}

int sumFlower(){
    int result = 0;
    for(pair<int,int> p : flowerCordi){
        result += cost[p.first][p.second];
    }
    return result;
}

void backtracking(int cnt){
    if(cnt >= 3){
        int sum = sumFlower();
        minResult = min(sum, minResult);
        return;
    }

    for(int i=1; i<N-1; i++){
        for(int j=1; j<N-1; j++){
            if(!visited[i][j] && checkFlower(i,j)){
                visited[i][j] = true;
                flowerCordi.push_back(make_pair(i,j));
                backtracking(cnt+1);
                flowerCordi.pop_back();
                visited[i][j] = false;
            }
        }
    }
}

void solve(){
    backtracking(0);
    cout << minResult << endl;
}

int main() {
    init();
    solve();
    return 0;
}
