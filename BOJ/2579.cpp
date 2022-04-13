#include <iostream>
#include <vector>

using namespace std;

int max(int m, int n) {
	return m > n ? m : n;
}

int main() {
	int N;
	cin >> N;
	int stairs[301] = { 0 };
	int ax[301] = { 0 };
	int aa[301] = { 0 };
	int amax[301] = { 0 };

	for (int i = 1; i < N+1; i++) {
		cin >> stairs[i];
	}

	for (int i = 1; i < N + 1; i++) {
		if (i == 1) {
			aa[i] = stairs[i];
			ax[i] = stairs[i];
		}
		else {
			aa[i] = ax[i - 1] + stairs[i];
			ax[i] = amax[i - 2] + stairs[i];
		}
		amax[i] = max(aa[i], ax[i]);
	}

	cout << max(aa[N], ax[N]);



	// 10(0)
	// 20(0) 30(1)  -> 30
	// 25(0) 45(1)  -> 45
	// 55(0) -> 55
	// 55(0) -> 55
	// 75



}