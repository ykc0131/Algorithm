//
// Created by yooki on 2024/02/17.
//
#include <iostream>
#include <vector>
#define MAX_INF 10000000001
#define MIN_INF -10000000001

using namespace std;

int N;
int math[] = {0,0,0,0};
vector<int> numbers;

void init(){
    cin >> N;
    numbers.resize(N+1, 0);

    for(int i=0; i<N; i++){
        cin >> numbers[i];
    }

    for(int i=0; i<4; i++){
        cin >> math[i];
    }
}


int minN = MAX_INF, maxN = MIN_INF;
void cal(int idx, int result){
    if(idx==N){
        minN = min(minN, result);
        maxN = max(maxN, result);
        return;
    }

    for(int i=0; i<4; i++){
        int tmp = result;
        if(math[i]>0){
            math[i]-=1;
            switch(i){
                case 0 : tmp += numbers[idx]; break;
                case 1 : tmp -= numbers[idx]; break;
                case 2 : tmp *= numbers[idx]; break;
                case 3 : tmp /= numbers[idx]; break;
            }
            cal(idx+1, tmp);
            math[i]+=1;
        }
    }
}

void solve(){
    cal(1,numbers[0]);

    cout << maxN << "\n" << minN << "\n";
}

int main(){
    init();
    solve();
    return 0;
}