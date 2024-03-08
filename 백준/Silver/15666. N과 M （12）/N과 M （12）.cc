//
// Created by yooki on 2024/03/08.
//
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int N,M;
vector<int> vec;
map<int,int> m;
void init(){
    cin >> N >> M;

    for(int i=0; i<N; i++){
        int n;
        cin >> n;
        m[n] = 1;
    }

    for(auto iter = m.begin(); iter!=m.end(); iter++){
        vec.push_back(iter->first);
    }
    N = vec.size();
    sort(vec.begin(), vec.end());
}

vector<string> result;
void backtracking(int n, string s, int cnt){
    if(cnt==M){
        result.push_back(s);
        return;
    }

    for(int i=n; i<N; i++){
        backtracking(i, s+to_string(vec[i])+" ", cnt+1);
    }
}

void solve(){
    backtracking(0, "",0);

    for(string s : result){
        cout << s << "\n";
    }
}

int main(){
    init();
    solve();
    return 0;
}