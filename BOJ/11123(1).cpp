#include <iostream>
#include <vector>

using namespace std;

int H,W;
vector<int> dfsCheck;
vector<vector<int>> graph;
vector<vector<char>> vec;
int result=0;
void graphMaker(int y,int x){
    int index = W*y+x;

    if(x+1<W){
        if(vec[y][x+1]=='#'){
            int newIndex=index+1;
            graph[index].push_back(newIndex);
            graph[newIndex].push_back(index);
        }
    }

    if(y+1<H){
        if(vec[y+1][x]=='#'){
            int newIndex=index+W;
            graph[index].push_back(newIndex);
            graph[newIndex].push_back(index);
        }
    }

    if(graph[index].size()==0){
        result++;
        dfsCheck[index]=1;
    }
}

void dfs(int n){
    dfsCheck[n]=true;

    int size = graph[n].size();
    for(int i=0; i<size;i++){
        int index = graph[n][i];
        if(!dfsCheck[index])
            dfs(index);
    }
}

int main() {
    int T;
    cin >> T;
    while(T--){
        cin >> H >> W;
        vec.resize(H,vector<char>(W,0));
        graph.resize(H*W,vector<int>());
        dfsCheck.resize(H*W,0);
        for(int i=0; i<H;i++){
            for(int j=0; j<W;j++){
                cin >> vec[i][j];
            }
        }

        for(int i=0; i<H;i++) {
            for (int j = 0; j < W; j++) {
                if (vec[i][j] == '#')
                    graphMaker(i, j);
                else
                    dfsCheck[W * i + j] = 1;
            }
        }

        for(int i=0; i<W*H;i++){
            if(!dfsCheck[i]){
                dfs(i);
                result++;
            }
        }

        cout << result<< endl;
        vec.clear();
        graph.clear();
        dfsCheck.clear();
        result=0;
    }
    return 0;
}