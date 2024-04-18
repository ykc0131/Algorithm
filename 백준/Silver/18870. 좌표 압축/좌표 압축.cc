#include <iostream>
#include <map>
#include <vector>

using namespace std;

int N;
map<int, int> m;
vector<int> vec;
void init() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		vec.push_back(n);

		m[n] = 1;
	}
}

void solve() {
	int index = 0;
	for (auto iter = m.begin(); iter != m.end(); iter++) {
		iter->second = index++;
	}

	vector<int> result;
	for (int i = 0; i < N; i++) {
		int value = vec[i];

		result.push_back(m[value]);
	}

	for (int i = 0; i < N; i++) {
		cout << result[i] << " ";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	init();
	solve();
	return 0;
}