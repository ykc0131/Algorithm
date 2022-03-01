#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int max(int m, int n) {
	return m > n ? m : n;
}

int main()
{
	int N;
	cin >> N;

	int result=0;
	int p[17];
	int t[17];
	int d[17] = { 0 };

	for (int i = 1; i < N+1; i++) {
		cin >> t[i] >> p[i];
	}

	
	for (int i = 1; i < N+1; i++) {
		if (i + t[i] <= N + 1) {
			d[i + t[i]] = max(d[i + t[i]], d[i] + p[i]);
			result = max(result, d[i + t[i]]);
		}

		d[i + 1] = max(d[i + 1], d[i]);
		result = max(result, d[i + 1]);
	}
	
	cout << result;
	
	return 0;
}

