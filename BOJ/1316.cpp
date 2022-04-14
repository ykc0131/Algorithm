#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int N;
	int result = 0; //결과
	cin >> N; //단어의 개수 N

	for (int i = 0; i < N; i++) {
		string word;
		cin >> word;
		vector<bool> alphabet(27, 0);

		bool isgroup=true;
		for (int j = 1; j < word.size(); j++) {
			if (alphabet[word[j] - 'a']) {
				isgroup = false;
				break;
			}
			if (word[j - 1] != word[j]) {
				if (alphabet[word[j - 1] - 'a']) {
					isgroup = false;
					break;
				}
				alphabet[word[j - 1] - 'a'] = true;
			}
		}

		result = isgroup == true ? result + 1 : result;
	}

	cout << result;
	
	return 0;
}