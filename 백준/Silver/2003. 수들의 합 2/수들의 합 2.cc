//
// Created by yooki on 2024/09/04.
//
#include <iostream>
#include <vector>

using namespace std;

int N,M;
vector<int> input;
void init(){
    cin >> N >> M;

    for(int i=0; i<N; i++){
        int n;
        cin >> n;
        input.push_back(n);
    }
}

void solve(){
    int left, right, cnt;
    left = right = cnt = 0;

    long result = 0;
    while( left <= right && right <= N ){
        if(result == M)
            cnt++;

        if( result <= M )
            result += input[right++];
        else
            result -= input[left++];
    }
    
    cout << cnt << endl;
}

int main(){
    init();
    solve();
    return 0;
}