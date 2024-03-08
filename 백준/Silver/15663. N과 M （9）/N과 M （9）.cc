//
// Created by yooki on 2024/03/08.
//
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int N,M;
vector<int> vec;
vector<bool> visited;
void init(){
    cin >> N >> M;

    vec.resize(N,0);
    visited.resize(N,false);
    for(int i=0; i<N; i++){
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
}

map<string,int> m;
vector<string> result;
void backtracking(string s, int cnt){
    if(cnt==M){
        if(m[s]==1)
            return;
        m[s] = 1;
        result.push_back(s);
        return;
    }

    for(int i=0; i<N; i++){
        int value = vec[i];
        if(!visited[i]){
            visited[i] = true;
            backtracking(s+to_string(value) + " " , cnt+1);
            visited[i] = false;
        }
    }
}

void solve(){
    backtracking("",0);
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