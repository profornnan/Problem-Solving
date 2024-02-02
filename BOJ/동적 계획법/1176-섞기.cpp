#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

constexpr int MAX_N = 16;

int N, K;
int height[MAX_N];
long long dp[1 << MAX_N][MAX_N];

long long dfs(int state, int last) {
	if (state == (1 << N) - 1)
		return 1;

	long long& ret = dp[state][last];

	if (ret != -1)
		return ret;

	ret = 0;

	for (int i = 0; i < N; ++i) {
		if (state & (1 << i))
			continue;

		if (abs(height[last] - height[i]) <= K)
			continue;

		ret += dfs(state | (1 << i), i);
	}

	return ret;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> K;

	for (int i = 0; i < N; ++i)
		cin >> height[i];

	memset(dp, -1, sizeof(dp));

	long long ans = 0;

	for (int i = 0; i < N; ++i)
		ans += dfs((1 << i), i);

	cout << ans << '\n';

	return 0;
}
