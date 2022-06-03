#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>

using namespace std;


int get_num(stack<int>* s) {
	int num = 0;
	for (int i = 0; !s->empty(); i++) {
		num += s->top() * pow(10, i);
		s->pop();
	}
	return num;
}

int plus_stack(stack<int>* s) {
	int num = 0;
	for (int i = 0; !s->empty(); i++) {
		num += s->top();
		s->pop();
	}
	return num;
}

int main() {
	string exp;
	cin >> exp;

	vector<int> num;
	vector<char> ope;
	stack<int> s;
	stack<int> cal_num;
	for (int i = 0; i < exp.size(); i++) {
		char c = exp[i];
		if (c >= '0' && c <= '9') {
			s.push((int)c - '0');
			continue;
		}

		if (c == '+' || c == '-') {
			int n = get_num(&s);
			if (c == '-') {
				if (!cal_num.empty()) {
					int end_mi = plus_stack(&cal_num) + n;
					num.push_back(end_mi);
				}
				else
					num.push_back(n);
				cal_num.push(0);
			}
			else {
				if (!cal_num.empty()) {
					cal_num.push(n);
					continue;
				}
				else
					num.push_back(n);
			}
			ope.push_back(c);

		}
	}

	int n = get_num(&s);
	if (!cal_num.empty()) {
		int end_mi = plus_stack(&cal_num) + n;
		num.push_back(end_mi);
	}
	else
		num.push_back(n);


	int result = num[0];
	for (int i = 1; i < num.size(); i++) {
		char op = ope[i - 1];
		switch (op)
		{
		case '+' : result += num[i];
			break;
		case '-' : result -= num[i];
			break;
		}
	}

	cout << result;
	return 0;
}