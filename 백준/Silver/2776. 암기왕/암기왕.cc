//
// Created by yooki on 2024/07/08.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M;
vector<int> nums;
vector<int> ans;
void init(){
    cin >> N;

    nums.clear();
    ans.clear();
    for(int i=0; i<N; i++){
        int n;
        cin >> n;
        nums.push_back(n);
    }

    cin >> M;
    for(int i=0; i<M; i++){
        int n;
        cin >> n;
        ans.push_back(n);
    }
}

int binaryTree(int l, int r, int n){
    int mid = (l+r)/2;

    if(nums[mid]==n)
        return 1;

    if(l>=r)
        return 0;

    if(nums[mid] > n)
        return binaryTree(l, mid-1, n);
    else
        return binaryTree(mid+1, r, n);
}

void solve(){
    sort(nums.begin(), nums.end());

    for(auto n : ans){
        cout << binaryTree(0,N-1, n) << "\n";
    }
}

int main(){
    int T;
    cin >> T;
    while(T--){
        init();
        solve();
    }
    return 0;
}