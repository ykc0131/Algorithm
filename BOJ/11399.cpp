////
//// Created by yooki on 2023/11/19.
////
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int N;
//vector<int> v;
//
//void init(){
//    cin >> N;
//    for(int i=0; i<N; i++){
//        int n;
//        cin >> n;
//        v.push_back(n);
//    }
//    sort(v.begin(),v.end());
//}
//
//void solve(){
//    long long result = 0;
//    for(int i=0; i<N; i++){
//        result += v[i] * (N-i);
//    }
//    cout << result << "\n";
//}
//
//int main(){
//    init();
//    solve();
//    return 0;
//}