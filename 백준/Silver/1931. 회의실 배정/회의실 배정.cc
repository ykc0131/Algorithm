//
// Created by yooki on 2024/03/06.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int,int>> vec;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

void init(){
    cin >> N;

    vec.clear();
    for(int i=0; i<N; i++){
        int n,m;
        cin >> n >> m;
        vec.push_back({n,m});
    }
    sort(vec.begin(), vec.end(), cmp);
}

void solve(){
    int end=0, cnt=0;
    for(int i=0; i<N; i++){
        if(end<=vec[i].first){
            end = vec[i].second;
            cnt+=1;
        }
    }
    cout << cnt << "\n";
}

int main(){
    init();
    solve();
    return 0;
}