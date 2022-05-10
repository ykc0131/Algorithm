#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> x(N + 1, 0);
	vector<int> y(N + 1, 0);
	vector<int> rank;

	for (int i = 0; i < N; i++) {
		cin >> x[i] >> y[i];
	}

	for (int i = 0; i < N; i++) {
		int ranking = 0;
		for (int j = 0; j < N; j++) {
			if (i == j)
				continue;
			if (x[i] < x[j] && y[i] < y[j])
				ranking++;
		}
		rank.push_back(++ranking);
	}

	for (int i = 0; i < N; i++) {
		cout << rank[i] << ' ';
	}
	return 0;
}