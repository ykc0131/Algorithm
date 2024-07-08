//
// Created by yooki on 2024/07/08.
//
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int,int>> input;
vector<int> vec;

void init(){
    cin >> N;

    for(int i=0; i<N; i++){
        int x,y;
        cin >> x >> y;
        input.push_back({x,y});
    }
    vec.resize(N,1);
}

void solve(){
    for(int i=0; i<N; i++){
        for(int j=0; j<i; j++){
            if(input[i].first > input[j].first && input[i].second > input[j].second)
                vec[j]++;
            else if(input[i].first < input[j].first && input[i].second < input[j].second)
                vec[i]++;
        }
    }

    for(int i=0; i<N; i++){
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main(){
    init();
    solve();
    return 0;
}