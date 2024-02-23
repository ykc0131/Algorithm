//
// Created by yooki on 2024/02/23.
//
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N;
vector<vector<int>> tree;

void init(){
    cin >> N;
    tree.clear();
    tree.resize(N,vector<int>(2,-1));

    for(int i=0; i<N; i++){
        char u,l,r;
        cin >> u >> l >> r;
        if(l!='.')
            tree[u-'A'][0] = l-'A';
        if(r!='.')
            tree[u-'A'][1] = r-'A';
    }
}

string ans[3] = {"","",""};
void preOrder(int n){
    if(n==-1)
        return;

    ans[0]+=(n+'A');
    int l = tree[n][0];
    preOrder(l);
    int r = tree[n][1];
    preOrder(r);
}

void inOrder(int n){
    if(n==-1)
        return;
    int l = tree[n][0];
    inOrder(l);
    ans[1]+=(n+'A');
    int r = tree[n][1];
    inOrder(r);
}

void postOrder(int n){
    if(n==-1)
        return;
    int l = tree[n][0];
    postOrder(l);
    int r = tree[n][1];
    postOrder(r);
    ans[2]+=(n+'A');
}


void solve(){
    preOrder(0);
    inOrder(0);
    postOrder(0);

    for(int i=0; i<3; i++){
        cout << ans[i] << endl;
    }
}

int main(){
    init();
    solve();
    return 0;
}