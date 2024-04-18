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
int index = 0;
int tracking(int n, int y, int x) {
	if (y==r && x==c)
		return index;

	int value = pow(n / 2, 2);
	if (r >= y + n / 2) {
		y += n / 2;
		index += value * 2;
	}

	if (c >= x + n / 2) {
		x += n / 2 ;
		index += value;
	}

	return tracking(n / 2, y, x);
	
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