//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <string>
//
//using namespace std;
//
//int main() {
//	int N, M;
//	cin >> N >> M;
//
//	vector<int> vec(N, 0);
//	for (int i = 0; i < N; i++) {
//		vec[i] = i + 1;
//	}
//	
//	if (N == M) {
//		do {
//			for (int i = 0; i < N; i++) {
//				cout << vec[i] << " ";
//			}
//			cout << "\n";
//		} while (next_permutation(vec.begin(), vec.end()));
//	}
//	else {
//		vector<int> preVec(M, 0);
//		vector<int> nowVec(M, 0);
//		do {
//			bool isSame = true;
//			string result = "";
//			for (int i = 0; i < M; i++) {
//				nowVec[i] = vec[i];
//				if (preVec[i] != nowVec[i]) {
//					isSame = false;
//				}
//				result += (to_string(nowVec[i]) + " ");
//			}
//
//			if (!isSame) {
//				cout << result << "\n";
//				preVec = nowVec;
//			}
//		} while (next_permutation(vec.begin(), vec.end()));
//	}
//
//	return 0;
//}