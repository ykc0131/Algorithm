//
// Created by yooki on 2024/01/11.
//
#include <iostream>
#include <queue>
#include <cmath>
#define MAXN 100001
using namespace std;

int N, K;
bool visited[MAXN] = {false,};

struct cmp{
    bool operator()(pair<int,int> a, pair<int,int> b){
        if(a.second == b.second){
            int _a = abs(a.first-K);
            int _b = abs(b.first-K);
            return _a > _b;
        }
        return a.second > b.second;
    }
};

void init(){
    cin >> N >> K;
}

void solve(){
    priority_queue<pair<int,int>, vector<pair<int,int>>,cmp> q;
    q.push({N,0});

    while(!q.empty()){
        int curN = q.top().first;
        int cnt = q.top().second; q.pop();

        if(visited[curN])
            continue;
        visited[curN]=true;
        if(curN == K){
            cout << cnt << "\n";
            break;
        }

        if(curN*2 < MAXN && !visited[curN*2] && curN < K)
            q.push({curN*2, cnt+0});
        if(curN+1 < MAXN && !visited[curN+1] && curN < K)
            q.push({curN+1,cnt+1});
        if(curN-1 >= 0 && !visited[curN-1])
            q.push({curN-1,cnt+1});
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.ignore(false);
    init();
    solve();
    return 0;
}