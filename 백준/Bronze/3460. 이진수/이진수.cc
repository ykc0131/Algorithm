//
// Created by yooki on 2024/07/26.
//
#include <iostream>

using namespace std;

int main(){
    int T;
    cin >> T;

    while(T--) {
        int n;
        cin >> n;

        int idx = 0;
        while (n != 0) {
            if(n%2)
                cout << idx << " ";
            n /= 2;
            idx++;
        }
        cout << endl;
    }

    return 0;
}