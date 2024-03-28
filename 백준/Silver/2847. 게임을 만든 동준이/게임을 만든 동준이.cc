//
// Created by yooki on 2024/03/28.
//
#include <iostream>
#include <vector>

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
    int result = 0;
    for(int i=N-1; i>0; i--){
        if(input[i] <= input[i-1]){
            result += (input[i-1]-input[i] + 1);
            input[i-1] = input[i]-1;
        }
    }

    cout << result << "\n";
}

int main(){
    init();
    solve();
    return 0;
}