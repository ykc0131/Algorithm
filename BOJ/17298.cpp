#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> v(N, 0), NGE(N, 0);
	stack<int> s;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	for (int i = N - 1; i >= 0; i--) {
		while (!s.empty() && s.top() <= v[i])
			s.pop();
		if (s.empty())
			NGE[i] = -1;
		else 
			NGE[i] = s.top();
		s.push(v[i]);
	}

	for (int i = 0; i < N; i++) {
		cout << NGE[i] << " ";
	}

	return 0;
}