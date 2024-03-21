#include <iostream>
using namespace std;

constexpr int INF = 21e8;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	int ans = 0;
	int prev = -INF;

	for (int i = 0; i < N; ++i) {
		int st, en;
		cin >> st >> en;

		if (en <= prev)
			continue;

		ans += en - (st <= prev ? prev : st);
		prev = en;
	}

	cout << ans << '\n';

	return 0;
}
