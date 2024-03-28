//
// Created by yooki on 2024/03/28.
//
#include <iostream>
#include <algorithm>

using namespace std;

long long X,Y,W,S;

void init(){
    cin >> X >> Y >> W >> S;
}

void solve(){
    int m = min(X,Y);
    long long result = m*min(2*W, S);

    X -= m;
    Y -= m;
    if(Y>0)
        X = Y;

    if(X>0) {
        if (X / 2 > 0) {
            result += X / 2 * min(2*W, 2*S);
            X %=2;
        }

        if(X != 0)
            result += W;
    }

    cout << result << "\n";
}

int main(){
    init();
    solve();
    return 0;
}