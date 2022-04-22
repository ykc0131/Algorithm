#include <iostream>
#include <vector>
#include <stack>

using namespace std;

stack<int> s;
vector<bool> numList;
vector<char> rv;
bool can = true;

void cal(int n) {
	if (!s.empty() && s.top() > n) {
		can = false;
		return;
	}

	int start = 0;
	if (!s.empty())
		start = s.top();

	for (int i = start + 1; i < n + 1; i++) {
		if (!numList[i]) {
			s.push(i);
			rv.push_back('+');
		}
	}
	s.pop();
	rv.push_back('-');
	numList[n] = true;
}

int main() {
	int N;
	cin >> N;

	numList.resize(N + 1, false);
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		cal(num);
		if (!can) {
			cout << "NO";
			break;
		}
	}

	if (can) {
		for (int i = 0; i < rv.size(); i++) {
			cout << rv[i] << "\n";
		}
	}

	return 0;
}