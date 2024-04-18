#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int N, M;
map<string,int> m;
void init() {
	cin >> N >> M;

	
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		m[s] += 1;
	}

	for (int i = 0; i < M; i++) {
		string s;
		cin >> s;
		m[s] += 1;
	}
}

void solve() {
	vector<string> result;
	for (auto iter = m.begin(); iter != m.end(); iter++) {
		if (iter->second == 2)
			result.push_back(iter->first);
	}

	sort(result.begin(), result.end());

	cout << result.size() << "\n";
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	init();
	solve();
}