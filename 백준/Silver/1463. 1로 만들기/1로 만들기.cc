//
// Created by yooki on 2024/02/22.
//
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int X;
vector<int> vec;

void init(){
    cin >> X;
    vec.clear();
    vec.resize(X+1,X+1);
    vec[1] = 0;
}

void solve(){
    for(int i=2; i<X+1; i++){
      if(i%3==0)
          vec[i] = min(vec[i], vec[i/3]+1);
      if(i%2==0)
          vec[i] = min(vec[i], vec[i/2]+1);
      vec[i] = min(vec[i], vec[i-1]+1);
    }

    cout << vec[X] << endl;
}

int main(){
    init();
    solve();
    return 0;
}