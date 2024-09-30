//
// Created by yooki on 2024/09/28.
//
#include <iostream>
#include <vector>

using namespace std;

int N, S;
vector<int> vec;
void init(){
    cin >> N >> S;

    for(int i=0; i<N; i++){
        int n;
        cin >> n;
        vec.push_back(n);
    }
}

int result = 0;
void btr(int idx, long long num){
    if(idx > N){
        return;
    }

    for(int i=idx; i<N; i++){
        if(num+vec[i]==S)
            result++;
        btr(i+1, num+vec[i]);
    }
}

void solve(){
    btr(0,0);
    cout << result << "\n";
}

int main(){
    init();
    solve();
    return 0;
}