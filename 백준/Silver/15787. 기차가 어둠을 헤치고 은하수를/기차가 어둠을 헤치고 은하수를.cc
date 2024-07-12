//
// Created by yooki on 2024/07/09.
//
#include <iostream>
#include <vector>
#include <string>
#include <map>
#define INIT "00000000000000000000"

using namespace std;

int N, M;
vector<string> vec;
map<string, int> m;
void init(){
    cin >> N >> M;

    for(int i=0; i<N; i++){
        vec.push_back(INIT);
    }
}

void solve(){
    for(int i=0; i<M; i++){
        int cmd, train,x;
        cin >> cmd >> train;
        train-=1;

        if(cmd==1 || cmd==2)
            cin >> x;

        switch (cmd) {
            case 1 :vec[train][x-1] = '1'; break;
            case 2 : vec[train][x-1] = '0'; break;
            case 3 : vec[train] = '0' + vec[train].substr(0,19); break;
            case 4 : vec[train] = vec[train].substr(1,19) + '0'; break;
        }
    }

    for(string s : vec){
        m[s]=1;
    }

    cout << m.size() << "\n";
}

int main(){
    init();
    solve();
    return 0;
}