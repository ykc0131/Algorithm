//
// Created by yooki on 2024/03/28.
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N,M;
vector<int> input;
void init(){
    cin >> N >> M;

    input.resize(N,0);
    for(int i=0; i<N; i++){
        cin >> input[i];
    }
    sort(input.begin(), input.end());
}

vector<string> result;
void backtracking(string s, int cnt){
    if(cnt==M){
        result.push_back(s);
        return;
    }

    for(int i=0; i<N; i++){
        backtracking(s+to_string(input[i])+" ", cnt+1);
    }
}

void solve(){
    for(int i=0; i<N; i++){
        backtracking(to_string(input[i])+" ", 1);
    }

    for(auto s : result) {
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