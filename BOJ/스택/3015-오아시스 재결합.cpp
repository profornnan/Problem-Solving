#include <iostream>
#include <stack>
using namespace std;

struct Person {
	int height;
	int cnt;
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	long long ans{};
	stack<Person> st;

	for (int i = 0; i < N; ++i) {
		int height;
		cin >> height;

		int cnt = 1;

		while (!st.empty() && st.top().height <= height) {
			if (st.top().height == height)
				cnt += st.top().cnt;

			ans += st.top().cnt;
			st.pop();
		}

		if (!st.empty())
			++ans;

		st.push({ height, cnt });
	}

	cout << ans << '\n';

	return 0;
}
