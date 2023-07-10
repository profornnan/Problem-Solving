#include <iostream>
#include <stack>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	long long ans = 0;
	stack<int> st;

	for (int i = 0; i < N; i++) {
		int h;
		cin >> h;

		while (!st.empty() && st.top() <= h)
			st.pop();

		ans += st.size();
		st.push(h);
	}

	cout << ans << '\n';

	return 0;
}
