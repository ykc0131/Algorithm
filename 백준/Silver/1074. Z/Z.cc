#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, r, c;
int maxN;
void init() {
	cin >> N >> r >> c;
	maxN = pow(2, N);
}

int dx[] = { 0,1,0,1 };
int dy[] = { 0,0,1,1 };
int index = 0;
int tracking(int n, int y, int x) {
	if (y < 0 || y >= maxN || x < 0 || x >= maxN)
		return -1;

	if (n == 2) {
		for (int i = 0; i < 4; i++) {
			int _y = y + dy[i];
			int _x = x + dx[i];
			
			index++;
			if (_y == r && _x == c) 
				return index - 1;
		}
	}
	else {
		int value = pow(n / 2, 2);
		if (r < y + n / 2 && c < x + n / 2) {
			return tracking(n / 2, y, x);
		}
		else if (r < y +  n / 2 && c >= x + n / 2) {
			index += value;
			return tracking(n / 2, y, x + n / 2);
		}
		else if (r >= y + n / 2 && c < x + n / 2) {
			index += value * 2;
			return tracking(n / 2, y + n / 2, x);
		}
		else if (r >= y + n / 2 && c >= x + n / 2) {
			index += value * 3;
			return tracking(n / 2, y + n / 2, x + n / 2);
		}
	}
}

void solve() {
	int ans = tracking(maxN, 0, 0);
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	init();
	solve();
	return 0;
}