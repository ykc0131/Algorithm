#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int N, M;
map<string, int> mName;
vector<string> vecName;
void init() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		mName[s] = i + 1;
		vecName.push_back(s);
	}
}

void solve() {
	vector<string> result;

	for (int i = 0; i < M; i++) {
		string s;
		cin >> s;

		if (s[0] - '0' >= 0 && s[0] - '0' <= 9) {
			int index = stoi(s);
			result.push_back(vecName[index-1]);
		}
		else 
			result.push_back(to_string(mName[s]));
	}

	for (string s : result) {
		cout << s << "\n";
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