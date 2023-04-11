//#include <iostream>
//#include <vector>
//
//using namespace std;
//int n,m;
//vector<vector<int>> vec;
//vector<vector<int>> check;
//int maxWid=0,wid=0;
//int dx[4] ={0,1,0,-1};
//int dy[4] = {-1,0,1,0};
//
//void dfs(int y,int x){
//    wid++;
//    check[y][x]=1;
//
//    for(int i=0; i<4;i++){
//        int newX = x+dx[i];
//        int newY = y+dy[i];
//        if(newX>=0 && newX <m && newY>=0 && newY<n )
//            if(vec[newY][newX]==1 && !check[newY][newX])
//                dfs(newY,newX);
//    }
//}
//
//int main() {
//    cin >>n>>m;
//    vec.resize(n,vector<int>(m,0));
//    check.resize(n,vector<int>(m,0));
//
//    for(int i=0; i<n;i++){
//        for(int j=0; j<m;j++){
//            cin >> vec[i][j];
//        }
//    }
//
//    int cnt=0;
//    for(int i=0; i<n;i++){
//        for(int j=0;j<m;j++){
//            if(vec[i][j]==1 && !check[i][j]){
//                cnt++;
//                dfs(i,j);
//                maxWid = maxWid > wid ? maxWid : wid;
//                wid=0;
//            }
//        }
//    }
//
//    cout << cnt << "\n" << maxWid << "\n";
//    return 0;
//}
