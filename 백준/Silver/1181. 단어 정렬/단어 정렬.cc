//
// Created by yooki on 2024/07/08.
//
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int N;
vector<map<string,int>> v(51);

void init(){
   cin >> N;

   for(int i=0; i<N; i++){
       string s;
       cin >> s;

       v[s.size()][s] = 1;
   }
}

void solve(){
    for(int i=1; i<51; i++){
        for(auto iter = v[i].begin(); iter != v[i].end(); iter++){
            cout << iter->first << "\n";
        }
    }
}

int main(){
    init();
    solve();
    return 0;
}