#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	int max = -10000001, result = 0;
	vector<int> v(N, 0);
	for (int i = 0; i < N; i++) { 
		cin >> v[i];
		result += v[i]; 
		if (i >= K - 1) { 
			max = max > result ? max : result;
			result -= v[i - K + 1]; 
		}
	}

	cout << max;

	return 0;
}