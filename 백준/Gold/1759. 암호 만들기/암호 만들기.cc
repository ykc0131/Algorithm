//
// Created by yooki on 2024/03/29.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int L,C;
vector<pair<char,int>> inputs;

bool cmp(pair<char,int> a, pair<char,int> b){
    return a.first < b.first;
}

void init(){
    cin >> L >> C;

    for(int i=0; i<C; i++){
        char c;
        cin >> c;

        int mo = 0;
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
            mo = 1;

        inputs.push_back({c,mo});
    }

    sort(inputs.begin(), inputs.end(), cmp);
}

vector<string> result;
void backtracking(int idx, int check, string s, int cnt){
    if(cnt==L){
        if(check && (L-check>=2)) {
            result.push_back(s);
        }
        return;
    }

    if(idx>=C)
        return;

    for(int i=idx; i<C; i++){
        pair<char,int> cur = inputs[i];
        backtracking(i+1, check+cur.second, s+cur.first, cnt+1);
    }
}

void solve(){
    backtracking(0,0,"",0);

    for(auto s : result){
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