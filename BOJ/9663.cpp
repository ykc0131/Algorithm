#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int N, result = 0;
vector<int> chess_row;

bool locate_possible(int cur_row) {
	for (int i = 0; i < cur_row; i++) {
		if (chess_row[i] != -1 && (chess_row[i] == chess_row[cur_row] || (cur_row - i) == abs(chess_row[cur_row] - chess_row[i]))) {
			return false;
		}
	}
	return true;
}

void queen(int row) {
	if (row == N) {
		result++;
		return;
	}
	
	for (int i = 0; i < N; i++) {
		chess_row[row] = i;
		if (locate_possible(row)) {
			queen(row + 1);
		}
	}
}

int main() {
	cin >> N;
	chess_row.resize(N, -1);

	queen(0);
	cout << result;
	return 0;
}