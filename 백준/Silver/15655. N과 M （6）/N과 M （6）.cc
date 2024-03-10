//
// Created by yooki on 2024/03/10.
//
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int N,M;
vector<int> vec;
void init(){
    cin >> N >> M;
    vec.resize(N,0);
    for(int i=0; i<N; i++){
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
}

vector<string> result;
vector<bool> visited;
void backtracking(string s, int cnt, int idx){
    if(cnt==M){
        result.push_back(s);
        return;
    }

    for(int i=idx; i<N; i++){
        if(!visited[i]){
            visited[i] = true;
            backtracking(s+to_string(vec[i])+" ", cnt+1, i+1);
            visited[i] = false;
        }
    }
}

void solve(){
    visited.resize(N,false);
    backtracking("",0,0);

    for(string s : result){
        cout << s << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
    return 0;
}