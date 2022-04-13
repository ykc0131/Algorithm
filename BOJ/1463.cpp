#include <iostream>
#include <vector>

using namespace std;

int min(int m, int n) {
	return m < n ? m : n;
}

int main() {
	int X;
	cin >> X;

	vector<int> N(1000001);

	for (int i = 2; i < X+1; i++) {
		N[i] = i;
		if (i % 3 == 0) {
			N[i] = min(N[i],N[i / 3] + 1);
		}
		
		if (i % 2 == 0) {
			N[i] = min(N[i], N[i / 2] + 1);
		}

		N[i] = min(N[i], N[i-1] + 1);
	}
	cout << N[X] << endl;

	return 0;
}