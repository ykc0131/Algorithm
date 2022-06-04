#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> start_t;
map<int, int> fin_t;
int main() {
	int N, num = 0;
	cin >> N;

	start_t.resize(N, 0);
	for (int i = 0; i < N; i++) {
		int e;
		cin >> start_t[i] >> e;
		fin_t.insert({ i,e });
	}

	vector< pair<int, int>> v(fin_t.begin(), fin_t.end());
	sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
		if (a.second == b.second) {
			return start_t[a.first] < start_t[b.first];
		}
		return a.second < b.second;
	});

	int s_time = 0;
	for (auto iter = v.begin(); iter != v.end(); iter++) {
		if (s_time <= start_t[iter->first]) {
			s_time = iter->second;
			num++;
		}
	}
	cout << num;
}