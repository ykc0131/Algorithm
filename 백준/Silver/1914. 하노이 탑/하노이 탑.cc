//
// Created by yooki on 2024/02/23.
//
#include <iostream>
#include <cmath>

using namespace std;

int N;

void init(){
    cin >> N;
}

void hanoi(int n, int from, int by, int to){
    if(n==1)
        cout << from << " " << to << "\n";
    else{
        hanoi(n-1, from, to, by);
        cout << from << " " << to << "\n";
        hanoi(n-1,by, from, to);
    }
}

void solve(){
    string s = to_string(pow(2,N));
    int idx = s.find('.');
    s = s.substr(0,idx);
    s[s.length() - 1] -= 1;

    cout << s << "\n";
    if(N<=20)
        hanoi(N,1,2,3);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
    return 0;
}