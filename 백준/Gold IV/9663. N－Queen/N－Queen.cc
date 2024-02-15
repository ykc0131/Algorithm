//
// Created by yooki on 2024/02/15.
//

#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> grid;

void init(){
    cin >> N;
    grid.clear();
    grid.resize(N,vector<int>(N,false));
}

vector<pair<int,int>> queenCoordi;
bool queenAttack(pair<int,int> a){
    for(pair<int,int> b : queenCoordi) {
        if(a.first == b.first)
            return true;
        if(a.second == b.second)
            return true;
        if(a.first-b.first == a.second-b.second)
            return true;
        if(a.first+a.second == b.first+b.second)
            return true;
    }
    return false;
}

int result = 0;
void placeQueen(int y, int x, int cnt){
    if(cnt==N){
        result++;
        return;
    }

    for(int i=0; i<N; i++){
        if(!queenAttack({y+1,i})) {
            queenCoordi.push_back({y+1,i});
            placeQueen(y+1, i, cnt+1);
            queenCoordi.pop_back();
        }
    }
}

void solve(){
    for(int i=0; i<N/2; i++){
        queenCoordi.push_back({0,i});
        placeQueen(0,i, 1);
        queenCoordi.clear();
    }
    result*=2;
    if(N%2){
        queenCoordi.push_back({0,N/2});
        placeQueen(0,N/2, 1);
        queenCoordi.clear();
    }
    cout << result << "\n";
}

int main(){
    init();
    solve();
    return 0;
}