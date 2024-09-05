#include <iostream>
#include <stack>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	int ans = 0;
	stack<int> stk;

	for (int i = 0; i < N; ++i) {
		int height;
		cin >> height;

		while (!stk.empty()) {
			++ans;

			if (stk.top() <= height)
				stk.pop();
			else
				break;
		}

		stk.push(height);
	}

	cout << ans << '\n';

	return 0;
}
