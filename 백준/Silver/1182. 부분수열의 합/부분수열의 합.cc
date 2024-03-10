//
// Created by yooki on 2024/03/10.
//
#include <iostream>
#include <vector>

using namespace std;

int N,M,cnt;
vector<int> vec;
void init(){
    cin >> N >> M;
    cnt = 0;

    vec.resize(N,0);
    for(int i=0; i<N; i++){
        cin >> vec[i];
        if(vec[i]==M)
            cnt++;
    }
}

vector<bool> visited;
int result=0;
void backtracking(int idx, int cnt, int limit, int sum){
    if(cnt==limit){
        if(sum==M)
            result++;
        return;
    }

    for(int i=idx; i<N; i++){
        if(!visited[i]){
            visited[i] = true;
            backtracking(i+1 , cnt+1, limit, sum+vec[i]);
            visited[i] = false;
        }
    }
}

void solve(){
    for(int i=1; i<N+1; i++){ //1의 개수.
        visited.clear();
        visited.resize(N,false);
        backtracking(0,0,i,0);
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