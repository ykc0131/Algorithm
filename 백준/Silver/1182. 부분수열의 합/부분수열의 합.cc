//
// Created by yooki on 2024/03/10.
//
#include <iostream>
#include <vector>

using namespace std;

int N,M;
vector<int> vec;
void init(){
    cin >> N >> M;
    vec.resize(N,0);
    for(int i=0; i<N; i++){
        cin >> vec[i];
    }
}

int result=0, limit = 0;
void backtracking(int idx, int cnt, int sum){
    if(cnt==limit){
        if(sum==M)
            result++;
        return;
    }

    for(int i=idx; i<N; i++)
        backtracking(i+1 , cnt+1, sum+vec[i]);
}

void solve(){
    for(int i=1; i<N+1; i++){ //1의 개수.
        limit = i;
        backtracking(0,0,0);
    }
    cout << result << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    init();
    solve();
    return 0;
}