//
// Created by yooki on 2024/09/30.
//
#include <iostream>
#include <vector>

using namespace std;

vector<pair<int,int>> grid(26);
vector<vector<int>> input(5,vector<int>(5,0));
void init(){
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            int n;
            cin >> n;
            grid[n] = make_pair(i,j);
        }
    }

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            int n;
            cin >> n;
            input[i][j] = n;
        }
    }
}

vector<pair<int,int>> colored;
int bingo=0;
void checkBingo(pair<int,int> target){
    int check[4] = {0,0,0,0};

    for(pair<int,int> c : colored){
        if(target.first == c.first)
            check[0]+=1;
        else if(target.second == c.second)
            check[1]+=1;
        else if(target.first-c.first == target.second-c.second)
            check[2]+=1;
        else if(target.first-c.first == c.second-target.second)
            check[3]+=1;
    }

    bingo += ((check[0]==4? 1:0) + (check[1]==4? 1:0) + (check[2]==4? 1:0) + (check[3]==4? 1:0));
}

void solve(){
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            int n = input[i][j];

            checkBingo(grid[n]);
            if(bingo>=3){
                cout << i*5 + j + 1 << "\n";
                return;
            }

            colored.push_back(grid[n]);
        }
    }
}

int main(){
    init();
    solve();
    return 0;
}