//
// Created by yooki on 2024/03/29.
//
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int L,C;
vector<int> moeum;
vector<int> jaeum;
vector<pair<int,int>> inputs;

bool cmp(pair<int,int> a, pair<int,int> b){
    return a.first < b.first;
}

void init(){
    cin >> L >> C;

    for(int i=0; i<C; i++){
        char c;
        cin >> c;

        int mo = 0;
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
            mo = 1;
            moeum.push_back(c-'a');
        }
        else
            jaeum.push_back(c-'a');

        inputs.push_back({c-'a',mo});
    }

    sort(moeum.begin(), moeum.end());
    sort(jaeum.begin(), jaeum.end());
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
        pair<int,int> cur = inputs[i];
        char c = cur.first + 'a';

        backtracking(i+1, check+cur.second, s+c, cnt+1);
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