#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, c;
	cin >> N;

	vector<int> d(N - 1, 0);
	vector<pair<int, int>> city;
	for (int i = 0; i < N - 1; i++)
		cin >> d[i];

	for (int i = 0; i < N; i++) {
		cin >> c;
		city.push_back(make_pair(i, c));
	}

	int cost = city[0].second;
	int result = 0;
	for (int i = 0; i < N - 1; i++) {
		int each_cost = city[i].second;
		cost = each_cost < cost ? each_cost : cost;
		result += cost * d[i];
	}

	cout << result;
	return 0;
}