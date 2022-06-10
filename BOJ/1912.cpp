﻿#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> v(N, 0), vv;

	int result = 0, max = -1001;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		if (v[i] > 0)
			result += v[i];
		else {
			if (result != 0)
				vv.push_back(result);
			vv.push_back(v[i]);
			result = 0;
		}
	}

	for (int i = 0; i < vv.size(); i++) {
		if (result + vv[i] < 0)
			result = 0;
		result += vv[i];
		max = max > result ? max : result;
	}

	cout << max;

	return 0;
}