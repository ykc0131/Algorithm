//
// Created by yooki on 2024/07/17.
//
#include <iostream>
#include <vector>

using namespace std;

vector<long long> vec;
int main(){
    int T;
    cin >> T;

    vec.resize(102,0);
    vec[1] = 1;
    vec[2] = 1;
    vec[3] = 1;
    while(T--){
        int N;
        cin >> N;

        for(int i=4; i<N+1; i++){
            vec[i] = vec[i-2] + vec[i-3];
        }

        cout << vec[N] << endl;
    }

    return 0;
}