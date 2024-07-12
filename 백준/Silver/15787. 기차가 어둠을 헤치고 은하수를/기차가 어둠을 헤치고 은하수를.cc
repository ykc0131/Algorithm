//
// Created by yooki on 2024/07/09.
//
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int N, M;
vector<int> vec;
map<int, int> m;
void init(){
    cin >> N >> M;

    for(int i=0; i<N; i++){
        vec.push_back(0);
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
            case 1 :vec[train] |= ( 1 <<  x ); break;
            case 2 : vec[train] &= ~( 1 << x ); break;
            case 3 : vec[train] = vec[train] << 1;
                     vec[train] &= (( 1 << 21 ) - 1 );
                     break;
            case 4 : vec[train] = vec[train] >> 1;
                     vec[train] &= ~1;
                     break;
        }
    }

    for(int i : vec){
        m[i]=1;
    }

    cout << m.size() << "\n";
}

int main(){
    init();
    solve();
    return 0;
}