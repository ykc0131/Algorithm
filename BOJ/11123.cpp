//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int H,W;
//vector<vector<char>> vec;
//vector<vector<int>> check;
//
//int dfs(int y,int x){
//    check[y][x]=true;
//    int num=1;
//    if(y-1>=0){
//        if(vec[y-1][x]=='#' && !check[y-1][x]){
//            num+=dfs(y-1,x);
//        }
//    }
//    if(x+1<W){
//        if(vec[y][x+1]=='#' && !check[y][x+1])
//            num+=dfs(y,x+1);
//    }
//
//    if(y+1<H){
//        if(vec[y+1][x]=='#' && !check[y+1][x])
//            num+=dfs(y+1,x);
//    }
//
//    if(x-1>=0){
//        if(vec[y][x-1]=='#' && !check[y][x-1]){
//            num+=dfs(y,x-1);
//        }
//    }
//    return num;
//}
//
//int main(){
//    int T;
//    cin >> T;
//    while(T--){
//        cin >> H >> W;
//        vec.resize(H,vector<char>(W,0));
//        check.resize(H,vector<int>(W,0));
//
//        for(int i=0; i<H;i++){
//            for(int j=0; j<W;j++){
//                cin >> vec[i][j];
//            }
//        }
//
//        int result=0;
//        for(int i=0; i<H;i++){
//            for(int j=0; j<W;j++){
//                if(vec[i][j]=='#'&&!check[i][j]){
//                    dfs(i,j);
//                    result++;
//                }
//            }
//        }
//        cout << result << endl;
//        vec.clear();
//        check.clear();
//    }
//    return 0;
//}