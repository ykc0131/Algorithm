//
// Created by yooki on 2024/02/21.
//
//easy version
#include <iostream>

using namespace std;

int main(){
    int N,M;
    cin >> N >> M;

    if(N==1 || M==1)
        cout << 1 << endl;
    else if(N>=3){
        if(M>=7)
            cout << M-2 << endl;
        else if(M>=5)
            cout << 4 << endl;
        else
            cout << M << endl;
    }
    else{
        if(M>=7)
            cout << 4 << endl;
        else if(M>=5)
            cout << 3 << endl;
        else if(M>=3)
            cout << 2 << endl;
        else
            cout << 1 << endl;
    }
    return 0;
}