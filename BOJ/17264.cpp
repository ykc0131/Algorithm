#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main() {
	int N, P, W, L, G;
	cin >> N >> P >> W >> L >> G;

	map<string, char> peo;
	for (int i = 0; i < P; i++) {
		string name;
		char can_win;
		cin >> name >> can_win;
		peo.insert({ name, can_win });
	}
	
	int score = 0;
	for (int i = 0; i < N; i++) {
		string name;
		cin >> name;

		char a = 'L';
		if(peo.count(name)!=0)
			a = peo.find(name)->second;
		if (a =='W')
			score += W;
		else
			score -= L;
		score = score < 0 ? 0 : score;

		if (score >= G) {
			cout << "I AM NOT IRONMAN!!";
			break;
		}
		else if (i == N - 1) 
			cout << "I AM IRONMAN!!";
	}

	return 0;
}