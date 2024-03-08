//
// Created by yooki on 2024/03/08.
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N,M;
vector<int> check;
void init(){
    cin >> N >> M;
    check.resize(N+1,0);
}

vector<string> result;
void backtracking(string s, int cnt){
    if(cnt==M){
        result.push_back(s);
        return;
    }

    for(int i=0; i<N; i++){
        if(!check[i]){
            check[i] = true;
            backtracking(s+to_string(i+1)+" ",cnt+1);
            check[i] = false;
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