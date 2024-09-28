//
// Created by yooki on 2024/09/28.
//
#include <iostream>
#include <cmath>

using namespace std;

int N,M;
int mal[10] = {0,};

void init(){
    cin >> N >> M;
    for(int i=0; i<M; i++){
        int n;
        cin >> n;
        mal[n] = 1;
    }
}

void solve(){
    if(N==100){
        cout << 0 << endl;
        return;
    }

    int min = abs(N-100);
    int s = abs(N - 100) > N ? 0 : N - abs(N - 100);
    int e = N < 100 ? 100 : N + abs(N-100);

    for(int i=s; i<e; i++) {
        int tmp = i, cnt = 0;
        bool cant = false;

        if(i==0){
            if(mal[tmp%10]==1)
                cant = true;
            cnt = 1;
        }
        else{
            while(tmp!=0) {
                if(mal[tmp%10]==1){
                    cant = true; break;
                }
                tmp /= 10;
                cnt++;
            }
        }

        if(!cant){
            min = min < cnt + abs(N-i) ? min : cnt + abs(N-i);
        }
    }

    cout << min << endl;
}

int main(){
    init();
    solve();
    return 0;
}