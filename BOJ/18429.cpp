#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	vector<int> num(N, 0);
	vector<int> training(N, 0);
	for (int i = 0; i < N; i++) {
		int A;
		cin >> A;
		training[i] = A - K;
		num[i] = i;
	}

	int count = 0;
	do {
		int result = 0;
		for (int i = 0; i < N; i++) {
			int index = num[i];
			result += training[num[i]];
			if (result < 0)
				break;
			else if (i == N - 1)
				count++;
		}
	} while (next_permutation(num.begin(), num.end()));

	cout << count;
	return 0;
}