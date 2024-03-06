//
// Created by yooki on 2024/03/06.
//
#include <iostream>
#include <algorithm>
#define INF 500000

using namespace std;

int N,M;
int nums[10] = {0,};
void init(){
    cin >> N >> M;

    for(int i=0; i<M; i++) {
        int n;
        cin >> n;
        nums[n] = 1;
    }
}

int broken(int n){
    string s = to_string(n);
    for(int i=0; i<s.length(); i++){
        if(nums[s[i]-'0']==1)
            return true;
    }
    return false;
}

void solve(){
    int minCnt = abs(N-100);
    for(int i=0; i<=INF*2+1; i++){
        if(!broken(i)){
            int cnt = abs(N-i) + to_string(i).length();
            minCnt = min(minCnt, cnt);
        }
    }
    cout << minCnt << "\n";
}

int main(){
    init();
    solve();
    return 0;
}