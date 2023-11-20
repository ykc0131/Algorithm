//
// Created by yooki on 2023/11/19.
//
#include <iostream>
#include <vector>


using namespace std;

int N,K;
vector<int> v;

void init(){
    cin >> N >> K;
    v.clear();
    for(int i=0; i<N;i++){
        int n;
        cin >> n;
        v.push_back(n);
    }
}

void solve(){
    int cnt=0;
    for(int i=N-1;i>=0;i--){
        if(K<v[i])
            continue;
        cnt += K/v[i];
        K %= v[i];
    }
    cout << cnt << "\n";
}

int main() {
    init();
    solve();
    return 0;
}
