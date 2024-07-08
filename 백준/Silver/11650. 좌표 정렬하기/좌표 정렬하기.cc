//
// Created by yooki on 2024/07/08.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int,int>> input;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

void init(){
    cin >> N;

    for(int i=0; i<N; i++){
        int x,y;
        cin >> x >> y;
        input.push_back({x, y});
    }
}

void solve(){
    sort(input.begin(), input.end(), cmp);
    for(auto p : input){
        cout << p.first << " " << p.second << "\n";
    }
}

int main(){
    init();
    solve();
    return 0;
}