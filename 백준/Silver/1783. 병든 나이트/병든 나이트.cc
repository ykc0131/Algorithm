//
// Created by yooki on 2024/02/20.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

long long N,M;
unordered_map<int,int> m; //index number, visited
int method[] = {0,0,0,0};
pair<int,int> pairs[] = {{-2,1},{-1,2},{1,2},{2,1}};

void init(){
    cin >> N >> M;
    int index = (N-1)*M + 0;
    m.insert({index,1});
}

int maxN = 0;
void backtracking(int y, int x){
    int mSize = m.size();
    if(mSize>=5){
        if(method[0]&&method[1]&&method[2]&&method[3]){
            maxN = max(maxN, mSize);
        }
        else
            return;
    }
    else
        maxN = max(maxN, mSize);

    for(int i=0; i<4; i++){
        int _y = y+pairs[i].first;
        int _x = x+pairs[i].second;

        if(_y<0 || _x<0 || _y>=N || _x>=M)
            continue;
        int index = _y*M + _x;
        auto iter = m.find(index);
        if(iter==m.end()){ //없어야 들어옴
            m.insert({index,1});
            method[i]++;
            backtracking(_y, _x);
            method[i]--;
            iter = m.find(index);
            m.erase(iter);
        }
    }
}

void solve(){
    if(N>=3 && M>=7) //무조건 가능
        cout << M-2 << endl;
    else{
        backtracking(N-1,0);
        cout << maxN << endl;
    }
}

int main(){
    init();
    solve();
    return 0;
}