//
// Created by yooki on 2024/02/23.
//
#include <iostream>
#include <vector>
#include <cmath>
#define MAXN 20000

using namespace std;

int N;
vector<vector<int>> vec;
vector<int> check;

void init(){
    cin >> N;
    vec.clear();
    check.clear();
    vec.resize(N+1,vector<int>(N+1,0));
    check.resize(N+1,false);

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> vec[i][j];
        }
    }
}

int result = MAXN;
void dfs(int n, int cnt){
    if(cnt == N/2) {
        int team1=0, team2=0;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(check[i] && check[j])
                    team1+=vec[i][j];
                if(!check[i] && !check[j])
                    team2+=vec[i][j];
            }
        }
        int diff = abs(team1-team2);
        result = min(result, diff);
        return;
    }

    for(int i=n; i<N; i++){
        check[i] = true;
        dfs(i+1,cnt+1);
        check[i] = false;
    }
}

void solve(){
    dfs(0,0);
    cout << result << endl;
}

int main(){
    init();
    solve();
    return 0;
}