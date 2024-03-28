//
// Created by yooki on 2024/03/28.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<int> input;
void init(){
    cin >> N;

    input.resize(N,0);
    for(int i=0; i<N; i++){
        cin >> input[i];
    }
}

void solve(){
    vector<int> result;
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=N-1; i>=0; i--){
        int cur = input[i];

        while(!pq.empty() && pq.top() <= cur)
            pq.pop();

        if(pq.empty())
            result.push_back(-1);
        else
            result.push_back(pq.top());

        pq.push(cur);
    }

    for(int i=N-1; i>=0; i--){
        cout << result[i] << " " ;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
    return 0;
}