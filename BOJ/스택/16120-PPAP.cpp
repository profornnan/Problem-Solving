#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	string str;
	cin >> str;

	stack<char> stk;

	for (const char& ch : str) {
		if (!stk.empty()) {
			if (stk.top() == 'A') {
				if (ch == 'A')
					break;

				if (stk.size() < 3)
					break;

				stk.pop();

				if (stk.top() != 'P')
					break;

				stk.pop();

				if (stk.top() != 'P')
					break;

				stk.pop();
			}
		}
		else if (ch == 'A')
			break;

		stk.push(ch);
	}

	cout << (stk.size() == 1 && stk.top() == 'P' ? "PPAP\n" : "NP\n");

	return 0;
}
