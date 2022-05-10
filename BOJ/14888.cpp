#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> num(N + 1, 0);
	vector<int> ope;
	vector<int> order;

	for (int i = 0; i < N; i++) {
		cin >> num[i];
		if (i < N - 1)
			order.push_back(i);
	}

	for (int i = 0; i < 4; i++) {
		int count;
		cin >> count;
		for (int j = 0; j < count; j++) {
			ope.push_back(i);
		}
	}

	int max = -1000000000, min = 1000000000;
	do {
		int result = num[0];
		for (int i = 0; i < N - 1; i++) {
			int _op = ope[order[i]];
			switch (_op)
			{
			case 0: result += num[i + 1];
				break;
			case 1: result -= num[i + 1];
				break;
			case 2: result *= num[i + 1];
				break;
			case 3: if (result < 0) {
						int positive = (-1)*result;
						result = (-1)*((int)positive / num[i + 1]);
					}
					else 
						result /= num[i + 1];
			}
		}
		max = max > result ? max : result;
		min = min < result ? min : result;

	} while (next_permutation(order.begin(), order.end()));

	cout << max << "\n" << min;

	return 0;
}