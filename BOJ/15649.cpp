#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<int> vec(N , 0);
	for (int i = 0; i < M; i++) {
		vec[i] = 1;
	}

	do {
		for (int i = 0; i < N; i++) {
			if (vec[i] != 0)
				cout << i + 1 << " ";
		}
		cout << endl;

	} while (prev_permutation(vec.begin(), vec.end()));


	return 0;
}