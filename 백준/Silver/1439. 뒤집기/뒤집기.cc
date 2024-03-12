//
// Created by yooki on 2024/03/12.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string s;
vector<int> result;
void init(){
    cin >> s;
    result.resize(s.size(),0);
}

void solve(){
    int zero = 0, one = 0, size = s.size();
    char pre = s[0];
    for(char c : s){
        if(pre!=c){
            if(pre-'0'==0)
                zero +=1;
            else
                one +=1;
            pre = c;
        }
    }

    if(s[size-1]-'0'==0)
        zero +=1;
    else
        one +=1;

    cout << min(zero, one) << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
    return 0;
}