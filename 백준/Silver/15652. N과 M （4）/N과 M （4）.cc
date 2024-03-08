//
// Created by yooki on 2024/03/08.
//
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N,M;
void init(){
    cin >> N >> M;
}

vector<string> str;
void backtracking(int n, string s, int cnt){
    if(cnt==M){
        str.push_back(s);
        return;
    }

    for(int i=n; i<N+1; i++){
        backtracking(i, s + (to_string(i) + " "),cnt+1);
    }
}

void solve(){
    backtracking(1, "",0);

    for(string s : str){
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