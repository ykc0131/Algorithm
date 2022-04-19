//#include <iostream>
//#include <cmath>
//#include <vector>
//
//using namespace std;
//
//int M, N;
//vector<bool> num;
//int main() {
//	cin >> M >> N;
//	num.resize(N + 1, false);
//
//	for (int i = 2; i <= sqrt(N); i++) {
//		if (num[i])
//			continue;
//		for (int j = i + 1; j <= N ; j++){
//			if (num[j])
//				continue;
//			else if (j%i == 0)
//				num[j] = true;
//		}
//	}
//
//	for (int i = M; i <= N; i++) {
//		if (!num[i] && i!=1)
//			cout << i << "\n";
//	}
//
//	return 0;
//}
