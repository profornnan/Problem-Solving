#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	string infix;
	cin >> infix;

	stack<char> stk;

	for (const char& ch : infix) {
		if (ch >= 'A' && ch <= 'Z') {
			cout << ch;
		}
		else if (ch == '+' || ch == '-') {
			while (!stk.empty() && stk.top() != '(') {
				cout << stk.top();
				stk.pop();
			}
			stk.push(ch);
		}
		else if (ch == '*' || ch == '/') {
			while (!stk.empty() && (stk.top() == '*' || stk.top() == '/')) {
				cout << stk.top();
				stk.pop();
			}
			stk.push(ch);
		}
		else if (ch == '(') {
			stk.push(ch);
		}
		else if (ch == ')') {
			while (stk.top() != '(') {
				cout << stk.top();
				stk.pop();
			}
			stk.pop();
		}
	}

	while (!stk.empty()) {
		cout << stk.top();
		stk.pop();
	}

	return 0;
}
