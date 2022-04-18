#include <iostream>
#include <vector>

using namespace std;
vector<bool> man(10002,false);

void dn(int n ) {
	int a = n / 1000;
	int b = (n - a * 1000) / 100;
	int c = (n - a * 1000 - b * 100) / 10;
	int d = (n - a * 1000 - b * 100 - c * 10);
	int nextN = n + a + b + c + d;
	if (nextN > 10000)
		return;
	else if (man[nextN])
		return;
	man[nextN] = true;
	dn(nextN);

	return;
}

int main() {
	for (int i = 1; i < 10001;i++) {
		if (!man[i]) {
			dn(i);
			cout << i << "\n";
		}
	}
}

/*
	for (int i = 1; i < 10001; i++) {
		if (man[i])
			continue;
		cout << i << "\n";
	}*/