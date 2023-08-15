#include <iostream>
#include <vector>

using namespace std;
int N;
vector<vector<char>> vec;
vector<vector<char>> vecNot;
int dx[4] ={0,1,0,-1};
int dy[4]={-1,0,1,0};

void dfs(int y,int x,char color){
    vec[y][x]='A';

    for(int i=0; i<4;i++){
        int newX = x +dx[i];
        int newY = y+dy[i];

        if(newX <0 || newY <0 || newX>=N || newY>=N)
            continue;
        if(vec[newY][newX]==color)
            dfs(newY,newX,color);
    }
}

void dfsNot(int y,int x,char color){
    vecNot[y][x]='A';

    for(int i=0; i<4;i++){
        int newX = x +dx[i];
        int newY = y +dy[i];

        if(newX <0 || newY <0 || newX>=N || newY>=N)
            continue;
        if(vecNot[newY][newX]==color)
            dfsNot(newY,newX,color);
    }
}

int main(){
    cin >> N;
    vec.resize(N,vector<char>(N,0));
    vecNot.resize(N,vector<char>(N,0));

    for(int i=0; i<N;i++){
        for(int j=0; j<N;j++){
            cin >> vec[i][j];
            if(vec[i][j]=='G')
                vecNot[i][j]='R';
            else
                vecNot[i][j] = vec[i][j];
        }
    }

    //vec
    int vecCnt=0;
    for(int i=0; i<N;i++){
        for(int j=0; j<N;j++){
            char value = vec[i][j];
            if(value!='A'){
               vecCnt++;
                dfs(i,j,value);
            }
        }
    }

    //vecNot
    int vecNotCnt=0;
    for(int i=0; i<N;i++){
        for(int j=0; j<N;j++){
            char value = vecNot[i][j];
            if(value!='A'){
                vecNotCnt++;
                dfsNot(i,j,value);
            }
        }
    }

    cout << vecCnt << " " << vecNotCnt;
    return 0;
}