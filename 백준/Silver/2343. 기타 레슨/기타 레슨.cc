//
// Created by yooki on 2024/01/26.
//
#include <iostream>
#include <vector>

using namespace std;

int N,M,sum;
vector<int> vec;
vector<int> blu_ray;

void init(){
    cin >> N >> M;
    vec.clear();
    vec.resize(N,0);

    sum=0;
    for(int i=0; i<N; i++){
        cin >> vec[i];
        sum+=vec[i];
    }
}

void solve(){
    int start = 1, end = sum, result = sum;
    while(start<=end){
        blu_ray.clear();
        blu_ray.resize(M,0);

        int mid = (start+end)/2, idx = 0, max = 0;
        bool cannot = false;
        for(int i=0; i<N && cannot==false; i++){
            if(blu_ray[idx] + vec[i] <= mid)
                blu_ray[idx] += vec[i];
            else{
                max = max > blu_ray[idx] ? max : blu_ray[idx];
                if(idx+1>=M)
                    cannot = true;
                else {
                    idx++;
                    blu_ray[idx] += vec[i];
                }
            }
        }
        max = max > blu_ray[idx] ? max : blu_ray[idx];
        if(cannot){
            start = mid + 1;
        }
        else{
            end = mid - 1;
            result = result < max ? result : max;
        }
    }

    cout << result << "\n";
}

int main(){
    init();
    solve();
    return 0;
}