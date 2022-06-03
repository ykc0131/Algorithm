#include <iostream>
#include <string>
#include <stack>
#include <cmath>

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

void cal(char c, int* prev, int n) {
	switch (c)
	{
	case '+': *prev += n; break;
	case '-': *prev -= n; break;
	}
}

int main() {
	string exp;
	cin >> exp;

	int num = 0;
	char ope = '+';
	stack<int> s, cal_num;
	for (int i = 0; i < exp.size(); i++) {
		char c = exp[i];
		if (c >= '0' && c <= '9') {
			s.push((int)c - '0');
			if (i < exp.size() - 1)
				continue;
		}
		int n = get_num(&s);
		if (c == '+') {
			if (!cal_num.empty()) {
				cal_num.push(n);
				continue;
			}
			else
				cal(ope, &num, n);
		}
		else {
			if (!cal_num.empty()) {
				int end_mi = plus_stack(&cal_num) + n;
				cal(ope, &num, end_mi);
			}
			else
				cal(ope, &num, n);
			cal_num.push(0);
		}
		ope = c;
	}

	cout << num;
	return 0;
}