#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	string str;
	cin >> str;

	int ans = 0;
	int now = 1;
	stack<char> stk;

	for (int i = 0; i < str.size(); ++i) {
		const char ch = str[i];

		if (ch == '(' || ch == '[') {
			stk.push(ch);
			now *= (ch == '(' ? 2 : 3);
			continue;
		}

		if (stk.empty()) {
			ans = 0;
			break;
		}

		if (ch == ')') {
			if (stk.top() != '(')
				break;

			if (str[i - 1] == '(')
				ans += now;

			now /= 2;
			stk.pop();
		}
		else if (ch == ']') {
			if (stk.top() != '[')
				break;

			if (str[i - 1] == '[')
				ans += now;

			now /= 3;
			stk.pop();
		}
	}

	if (!stk.empty())
		ans = 0;

	cout << ans << '\n';

	return 0;
}
