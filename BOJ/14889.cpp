#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int N;
	cin >> N;
	
	vector<vector<int>> team(N, vector<int>(N, 0));
	vector<int> set_team(N - 1, 0);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> team[i][j];
		}
	}

	for (int i = 0; i < N / 2 - 1; i++) {
		set_team[i] = 1;
	}

	int min = 100 * N;
	do {
		vector<int> tem_team;
		int team_r = 0;

		tem_team.push_back(1);
		tem_team.insert(tem_team.end(), set_team.begin(), set_team.end());

		for (int i = 0; i < N; i++) {
			int my_t_num = tem_team[i];
			for (int j = 0; j < N; j++) {
				if (my_t_num==0 && tem_team[j] == my_t_num) 
					team_r += team[i][j];
				else if (my_t_num == 1 && tem_team[j] == my_t_num) 
					team_r -= team[i][j];
			}
		}

		min = min < abs(team_r) ? min : abs(team_r);
	} while (prev_permutation(set_team.begin(), set_team.end()));

	cout << min;

	return 0;
}