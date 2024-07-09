//
// Created by yooki on 2024/07/09.
//
#include <iostream>
#include <string>
#include <map>

using namespace std;

string s;
map<string, int> m;
void init(){
    cin >> s;
    m.clear();
}

void solve(){
    for(int i=0; i<s.size(); i++) {
        for(int j=1; j<=s.size()-i; j++){
            m[s.substr(i,j)]++;
        }
    }

    cout << m.size() << "\n";
}

int main(){
    init();
    solve();
    return 0;
}