//
// Created by yooki on 2024/03/28.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define LOTTO 6

using namespace std;

int N;
vector<int> input;
vector<string> result;
void init(int n){
    result.clear();
    input.clear();

    N = n;
    input.resize(N,0);
    for(int i=0; i<N; i++){
        cin >> input[i];
    }
    sort(input.begin(), input.end());
}

void backtracking(int idx, string s, int cnt){
    if(cnt==LOTTO){
        result.push_back(s);
        return;
    }

    if(idx>=N)
        return;

    for(int i=idx; i<N; i++){
        backtracking(i+1,s+to_string(input[i]) + " ", cnt+1);
    }
}

void solve(){
    backtracking(0,"",0);
    for(auto s : result)
        cout << s << "\n";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    while(cin >> n && n){
        init(n);
        solve();
    }
    return 0;
}