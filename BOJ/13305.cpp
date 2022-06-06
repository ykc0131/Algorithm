#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	long int c;
	cin >> N;

	vector<long int> d(N - 1, 0);
	vector<pair<int, long int>> city;
	for (int i = 0; i < N - 1; i++)
		cin >> d[i];

	for (int i = 0; i < N; i++) {
		cin >> c;
		city.push_back(make_pair(i, c));
	}

	long int cost = city[0].second, result = 0;
	for (int i = 0; i < N - 1; i++) {
		long int each_cost = city[i].second;
		cost = each_cost < cost ? each_cost : cost;
		result += cost * d[i];
	}

	cout << result;
	return 0;
}