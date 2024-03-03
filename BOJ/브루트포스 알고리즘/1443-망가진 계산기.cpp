#include <iostream>
#include <cmath>
using namespace std;

int D, P;
int ans = -1;
int digit;

void dfs(int cnt, int last, int now) {
	if (cnt >= P) {
		ans = ans > now ? ans : now;
		return;
	}

	for (int i = last; i <= 9; ++i) {
		int next = now * i;

		if (next / digit == 0)
			dfs(cnt + 1, i, next);
	}
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> D >> P;

	digit = pow(10, D);

	dfs(0, 2, 1);

	cout << ans << '\n';

	return 0;
}
