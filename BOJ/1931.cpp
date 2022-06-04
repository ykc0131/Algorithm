#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, s, e, num = 0;
	cin >> N;

	vector<pair<int, int>> t;
	for (int i = 0; i < N; i++) {
		cin >> s >> e;
		t.push_back(make_pair(s, e));
	}

	sort(t.begin(), t.end(), [](pair<int, int> a, pair<int, int> b) {
		if (a.second == b.second) {
			return a.first < b.first;
		}
		return a.second < b.second;
	});

	int s_time = 0;
	for (int i = 0; i < N; i++) {
		if (s_time <= t[i].first) {
			s_time = t[i].second;
			num++;
		}
	}
	cout << num;
}