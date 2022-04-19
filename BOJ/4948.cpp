#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<bool> num(246914, false);
int main() {
	int N, max = 1;
	cin >> N;

	while (N != 0) {
		int twoN = 2 * N;

		if (max < twoN) { // (max < twoN) �� max ���� �Ǻ�
			for (int i = 2; i <= sqrt(twoN); i++) {
				if (num[i])
					continue;
				for (int j = i + 1; j <= twoN; j++) {
					if (num[j])
						continue;
					else if(j%i==0)
						num[j] = true;
				}
			}
			max = twoN;
		}
		// (max >= twoN) �̹� max������ �Ҽ��Ǻ� �Ϸ�
		// �Ҽ��� ���� ����ϸ� ��

		int result = 0;
		for (int i = N + 1; i <= twoN; i++) {
			if (!num[i])
				result++;
		}
		cout << result << "\n";
		cin >> N;
	}

	return 0;
}