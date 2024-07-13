//
// Created by yooki on 2024/07/13.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> vec;
void init(){
    cin >> N;

    for(int i=0; i<N; i++){
        int n;
        cin >> n;
        vec.push_back(n);
    }
}

void solve(){
    sort(vec.begin(), vec.end(), less<int>());
    for(int v : vec)
        cout << v << "\n";
}

int main(){
    init();
    solve();
    return 0;
}