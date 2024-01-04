#include <iostream>
#include <stack>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	int ans{};
	stack<int> stk;

	for (int n = 0; n < N; ++n) {
		int x, y;
		cin >> x >> y;

		while (!stk.empty() && stk.top() > y) {
			stk.pop();
			++ans;
		}

		if (!stk.empty() && stk.top() == y)
			continue;

		stk.push(y);
	}

	while (!stk.empty() && stk.top() > 0) {
		stk.pop();
		++ans;
	}

	cout << ans << '\n';

	return 0;
}
