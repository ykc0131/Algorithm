//
// Created by yooki on 2024/10/08.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
struct cmp {
    bool operator()(pair<int,int> a, pair<int,int> b){
        if(a.first == b.first)
            return a.second > b.second;
        return a.first > b.first;
    }
};

vector<string> names;
int main(){
    int N;
    cin >> N;

    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    for(int i=0; i<N; i++){
        int age;
        string name;
        cin >> age >> name;
        names.push_back(name);
        pq.push({age, i});
    }

    while(!pq.empty()){
        cout << pq.top().first << " " << names[pq.top().second] << endl;
        pq.pop();
    }
    return 0;
}
