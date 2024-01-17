//
// Created by yooki on 2024/01/17.
//
#include <iostream>
#include <map>
#include <vector>
#define MAXN 10000001

using namespace std;

int N,M;
map<long long, int> cards;
vector<bool> isExist;
vector<int> ans;

void init(){
    cards.clear();
    isExist.clear();
    ans.clear();
    isExist.resize(MAXN*2, false);
}

void solve(){
    cin >> N;
    for(int i=0; i<N; i++){
        int n;
        cin >> n;
        n += MAXN;
        cards[n] += 1;
        isExist[n] = true;
    }

    cin >> M;
    for(int i=0; i<M; i++){
        int n;
        cin >> n;
        n += MAXN;
        if(isExist[n])
            ans.push_back(cards[n]);
        else
            ans.push_back(0);
    }

    for(int i=0; i<M; i++){
        cout << ans[i] << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.ignore(false);
    init();
    solve();
    return 0;
}