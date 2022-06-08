#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> v_m(M, 0);

	bool b = true;
	while (b) {
		int plus = 0;
		for (int i = 0; i < M; i++) 
			cout << v_m[i] + 1 << " ";

		++v_m[M - 1];
		for (int i = M - 1; i >= 0; i--) {
			if (i>0 && ((v_m[i] + plus) == N)) {
				v_m[i] = 0;
				plus = 1;
			}
			else {
				v_m[i] += plus;
				plus = 0;
			}

			if (i == 0 && v_m[i] == N) 
				b = false;
		}
		cout << endl;
	}

	return 0;
}