////
//// Created by yooki on 2023/11/20.
////
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int N;
//vector<vector<int>> v;
//
//void init(){
//    cin >> N;
//    v.clear();
//    v.resize(2,vector<int>(N,0));
//
//    for(int i=0; i<2; i++){
//        for(int j=0; j<N; j++){
//            cin >> v[i][j];
//        }
//    }
//    sort(v[0].begin(), v[0].end());
//    sort(v[1].begin(), v[1].end());
//}
//
//void solve(){
//    int result=0;
//    for(int i=0; i<N;i++){
//        result += (v[0][i] * v[1][N-i-1]);
//    }
//    cout << result << "\n";
//}
//
//int main(){
//    init();
//    solve();
//    return 0;
//}