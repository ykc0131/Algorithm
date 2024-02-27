//
// Created by yooki on 2024/02/27.
//
// Segment Tree
#include <iostream>
#include <vector>
#include <cmath>
#include <tuple>

using namespace std;
using ll = long long;
using tyl = tuple<ll,ll,ll>;

int N,M,K;
vector<ll> arr;
vector<ll> tree;
vector<tyl> inputs;

void init(){
    cin >> N >> M >> K;
    arr.clear();
    tree.clear();
    inputs.clear();

    arr.resize(N,0);
    int h = ceil(log2(N));
    tree.resize((1<<h+1),0);

    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    for(int i=0; i<M+K; i++){
        ll a,b,c;
        cin >> a >> b >> c;
        inputs.push_back({a,b,c});
    }
}

ll build(int node, int start, int end){
    if(start == end)
        return tree[node] = arr[start];

    int mid = (start+end)/2;
    return tree[node] = build(2*node, start, mid) + build(2*node+1, mid+1, end);
}

ll sum(int node, int start, int end, int left, int right){
    //case1 : 겹치지 않음
    if(left > end || right < start)
        return 0;
    //case2 : [left, right] > [start, end]
    if(left <= start && right >= end)
        return tree[node];

    int mid = (start+end)/2;
    return sum(2*node, start, mid, left, right) + sum(2*node+1, mid+1, end, left, right);
}

void update(int node, int start, int end, int index, ll diff){
    //case1 : 겹치지 않음
    if(index < start || index > end)
        return;

    //case2 : 포함 되어 있음
    tree[node] += diff;
    if(start==end)
        return;

    int mid = (start+end)/2;
    update(2*node, start, mid, index, diff);
    update(2*node+1, mid+1, end, index, diff);
}

void solve(){
    build(1,0,N-1);

    vector<ll> result;
    for(int i=0; i<M+K; i++){
        tyl t = inputs[i];

        switch (get<0>(t)) {
            case 1:{
                ll diff = get<2>(t) - arr[get<1>(t)-1];
                arr[get<1>(t)-1] = get<2>(t);
                update(1,0,N-1,get<1>(t)-1, diff);
                break;
            }
            case 2: {
                ll ans = sum(1, 0, N - 1, get<1>(t) - 1, get<2>(t) - 1);
                result.push_back(ans);
                break;
            }
        }
    }

    for(int i=0; i<result.size(); i++){
        cout << result[i] << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
    return 0;
}