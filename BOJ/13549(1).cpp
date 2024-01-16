//
// Created by yooki on 2024/01/11.
// 0-1 BFS 풀이

#include <iostream>
#include <deque>
#define MAXN 100001

using namespace std;

int N,K;
bool isVisited[MAXN] = {false,};

void init(){
    cin >> N >> K;
}

void solve(){
    deque<pair<int,int>> dq;
    dq.push_back({N,0});

    while(!dq.empty()){
        int curN = dq.front().first;
        int cnt = dq.front().second; dq.pop_front();
        if(isVisited[curN])
            continue;
        isVisited[curN] = true;
        if(curN==K){
            cout << cnt << "\n";
            break;
        }

        if(curN*2 < MAXN && isVisited[curN*2]==false && curN < K)
            dq.push_front({curN*2,cnt});

        if(curN+1 < MAXN && isVisited[curN+1]==false && curN < K)
            dq.push_back({curN+1,cnt+1});

        if(curN-1 >= 0 && isVisited[curN-1]==false)
            dq.push_back({curN-1,cnt+1});

    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.ignore(false);
    init();
    solve();
    return 0;
}
