#include <iostream>
#include <string>
#include <stack>
using namespace std;

constexpr int MAX_L = 50;

string str;
int rightIdx[MAX_L];

int getLength(const int& st, const int& en) {
	int len = 0;

	for (int i = st; i < en; ++i) {
		if (str[i] == '(') {
			len += (str[i - 1] - '0') * getLength(i + 1, rightIdx[i]) - 1;
			i = rightIdx[i];
		}
		else
			++len;
	}

	return len;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> str;

	stack<int> stk;

	for (int i = 0; i < str.size(); ++i) {
		char ch = str[i];

		if (ch == '(')
			stk.push(i);
		else if (ch == ')') {
			rightIdx[stk.top()] = i;
			stk.pop();
		}
	}

	cout << getLength(0, str.size()) << '\n';

	return 0;
}
