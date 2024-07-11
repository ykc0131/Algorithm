//
// Created by yooki on 2024/07/11.
//
#include <iostream>
#include <map>
#include <queue>

using namespace std;

int N;
map<string, int> books;
void init(){
    cin >> N;

    for(int i=0; i<N; i++){
        string s;
        cin >> s;
        books[s]++;
    }
}

struct cmp {
    bool operator()(pair<string,int> a, pair<string,int> b){
        if(a.second==b.second)
            return a.first > b.first;
        return a.second < b.second;
    }
};

priority_queue<pair<string, int>, vector<pair<string,int>>, cmp> pq;
void solve(){
    for(auto iter=books.begin(); iter!=books.end(); iter++){
        pq.push({iter->first, iter->second});
    }

    cout << pq.top().first << "\n";
}

int main(){
    init();
    solve();
    return 0;
}