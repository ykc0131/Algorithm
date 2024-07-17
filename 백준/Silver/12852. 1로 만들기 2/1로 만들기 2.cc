//
// Created by yooki on 2024/07/17.
//
#include <iostream>
#include <vector>
#define INF 1000001

using namespace std;

int N;
vector<int> vec;
void init(){
    cin >> N;

    vec.clear();
    vec.resize(N+1,INF);
}

void solve(){
    vec[1] = 0;
    for(int i=1; i<N+1; i++){
        if(i%3==0)
            vec[i] = min(vec[i], vec[i/3] + 1);
        if(i%2==0)
            vec[i] = min(vec[i], vec[i/2] + 1);

        vec[i] = min(vec[i], vec[i-1] + 1);
    }


    vector<int> ans;
    ans.push_back(N);
    cout << vec[N] << endl;

    int n = vec[N];
    while(n--){
        int tmp = 0;
        if(N%3==0 && vec[N/3]==n)
            tmp = N/3;
        if(N%2==0 && vec[N/2]==n)
            tmp = N/2;
        if(N-1>=1 && vec[N-1]==n)
            tmp = N-1;
        N = tmp;
        ans.push_back(N);
    }
    
    for(int i : ans){
        cout << i << " ";
    }
}

int main(){
    init();
    solve();
    return 0;
}