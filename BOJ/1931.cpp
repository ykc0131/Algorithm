#include <iostream>
#include <vector>
#include <map>

using namespace std;

int num = 0;
map<int, int> timeline;
void greedy() {
	int s_time = 0;
	for (auto iter = timeline.begin(); iter != timeline.end(); iter++) {
		if (s_time <= iter->second) {
			s_time = iter->first;
			cout << "다음 꺼 ( " << iter->second << " , " << iter->first << " )\n";
			num++;
		}
	}
}


int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int s, e;
		cin >> s >> e;
		timeline.insert({ e, s });
	}

	for (auto iter = timeline.begin(); iter != timeline.end(); iter++) {
		cout << iter->second << "  " << iter->first << endl;
	}

	//greedy();
	cout << num;
}