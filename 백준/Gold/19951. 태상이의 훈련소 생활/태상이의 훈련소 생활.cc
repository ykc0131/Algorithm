//
// Created by yooki on 2024/07/09.
//
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, M;
vector<int> vec;
vector<int> tree;
void init(){
    cin >> N >> M;

    for(int i=0; i<N; i++){
        int n;
        cin >> n;
        vec.push_back(n);
    }

    tree.resize(N+1,0);
    for(int i=0; i<M; i++){
        int a, b, k;
        cin >> a >> b >> k;

        tree[a] += k;
        tree[b+1] += -1*k;
    }
}

void solve(){
    int sum = 0;
    for(int i=1; i<N+1; i++){
        sum += tree[i];
        vec[i-1] += sum;
    }

    for(int i=0; i<N; i++){
        cout << vec[i] << " ";
    }
}

int main(){
    init();
    solve();
    return 0;
}