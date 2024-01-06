//
// Created by yooki on 2024/01/06.
//
#include <iostream>
#include <queue>

using namespace std;

int N;
priority_queue<long long, vector<long long>, less<long long>> pq_posi;
priority_queue<long long, vector<long long>, greater<long long>> pq_nega;

void init(){
    cin >> N;
    for(int i=0; i<N; i++){
        int num;
        cin >> num;
        if(num>0)
            pq_posi.push(num);
        else{
            pq_nega.push(num);
        }
    }
}

void solve(){
    int sum = 0;
    while(!pq_posi.empty()){
        int n1 = pq_posi.top(); pq_posi.pop();
        if(n1==1){
            sum+=n1;
            continue;
        }

        int n2;
        if(!pq_posi.empty()){
            n2 = pq_posi.top(); pq_posi.pop();
            if(n2==1){
                sum+=n1;
                sum+=n2;
                continue;
            }
            sum+= n1*n2;
        }
        else{
            sum+=n1;
        }
    }


    while(!pq_nega.empty()){
        int n1 = pq_nega.top(); pq_nega.pop();
        int n2;
        if(!pq_nega.empty()){
            n2 = pq_nega.top(); pq_nega.pop();
            if(n1*n2>=0)
                sum+= n1*n2;
            else{
                sum+=n1;
                sum+=n2;
            }
        }
        else{
            sum+=n1;
        }
    }
    cout << sum << endl;
}

int main(){
    init();
    solve();
    return 0;
}
