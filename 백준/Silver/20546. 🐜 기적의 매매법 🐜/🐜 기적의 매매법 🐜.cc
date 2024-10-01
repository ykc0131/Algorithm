//
// Created by yooki on 2024/10/01.
//
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> input(14,0);
void init(){
    cin >> N;

    int cnt = 0;
    int pre = 0;
    for(int i=0; i<14; i++){
        cin >> input[i];
    }
}

void solve(){
    pair<int,int> result = {N,N};
    pair<int,int> stock = {0,0};

    int posiCnt = 0, negaCnt = 0;
    for(int i=0; i<14; i++){
        int cost = input[i];

        // 1)
        if(result.first >= cost){
            stock.first = result.first / cost;
            result.first %= cost;
        }

        // 2)
        if(i>0){
            if(input[i]-input[i-1] > 0 ){
                negaCnt = 0;
                posiCnt++;

                if(posiCnt==3){
                    result.second += stock.second * cost;
                    posiCnt = 0;
                }
            }
            else if(input[i]-input[i-1] < 0 ){
                posiCnt = 0;
                negaCnt++;

                if(negaCnt==3 && result.second >= cost){
                    stock.second = result.second / cost;
                    result.second %= cost;
                    negaCnt = 0;
                }
            }
            else {
                posiCnt = negaCnt = 0;
            }
        }
    }

    int j = result.first + stock.first * input[13];
    int s = result.second + stock.second * input[13];
    if(j>s)
        cout << "BNP\n";
    else if(j<s)
        cout << "TIMING\n";
    else
        cout << "SAMESAME\n";

}


int main(){
    init();
    solve();
    return 0;
}