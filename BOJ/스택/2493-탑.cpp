#include <iostream>
#include <stack>
using namespace std;

constexpr int INF = 21e8;

struct Tower {
	int idx;
	int height;
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	stack<Tower> st;
	st.push({ 0, INF });

	for (int idx = 1; idx <= N; ++idx) {
		int height;
		cin >> height;

		while (st.top().height < height)
			st.pop();

		cout << st.top().idx << ' ';

		st.push({ idx, height });
	}

	return 0;
}
