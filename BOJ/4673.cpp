//#include <iostream>
//#include <vector>
//#include <ctime>
//
//using namespace std;
//
//int main() {
//	vector<bool> man(10002, 0);
//	bool end = false;
//
//	for (int a = 0; a < 10; a++) {
//		for (int b = 0; b < 10; b++) {
//			for (int c = 0; c < 10; c++) {
//				for (int d = 0; d < 10; d++) {
//					int n = 1001 * a + 101 * b + 11 * c + 2 * d;
//					if (n > 10000)
//						break;
//					else {
//						man[n] = true;
//					}
//				}
//			}
//		}
//	}
//
//	for (int i = 1; i < 10001; i++) {
//		if (man[i])
//			continue;
//		cout << i << "\n";
//	}
//}