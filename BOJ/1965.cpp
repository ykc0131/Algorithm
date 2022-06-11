#include <iostream>
#include <vector>
using namespace std;

vector<int> box(1001, 0);
int result = 0;
void dp(int n) {
	int index = n;
	int max = 0;
	while (--index>0) {
		if (box[index] == 0)
			continue;
		max = max > box[index] ? max : box[index];
	}

	box[n] = box[n]> max + 1 ? result : max + 1;
	result = result > max + 1 ? result : max + 1;
}
int main() {
	int N, n;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> n;
		dp(n);
	}
	
	cout << result;

	return 0;
}