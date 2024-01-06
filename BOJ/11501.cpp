//
// Created by yooki on 2024/01/05.
//
#include <iostream>
#include <vector>

using namespace std;

int T,N;
vector<int> vec;
vector<long long> ans;

void init(){
    cin >> N;
    vec.clear();
    vec.resize(N,0);

    for(int i=0; i<N; i++){
        cin >> vec[i];
    }
}

void solve(){
    int max = 0;
    long long sum = 0;
    for(int i=N-1; i>=0 ; i--){
        if(max <= vec[i]){
            max = vec[i];
            vec[i] = 0;
        }
        else{
            vec[i] = max - vec[i];
        }
        sum += vec[i];
    }

    ans.push_back(sum);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.ignore(false);

    cin >> T;
    while(T--){
        init();
        solve();
    }

    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << "\n";
    }

    return 0;
}
