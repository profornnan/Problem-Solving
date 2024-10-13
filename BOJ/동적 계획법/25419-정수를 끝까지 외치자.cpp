#include <iostream>
#include <cstring>
using namespace std;

constexpr int MAX_N = 100'000;

int N, K;
int dp[MAX_N + 1];

bool canWin(const int now) {
	if (now > N)
		return false;

	int& ret = dp[now];

	if (ret != -1)
		return ret;

	ret = true;

	for (int next = now + 1; next <= now + K; ++next)
		if (canWin(next))
			ret = false;

	return ret;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> K;

	memset(dp, -1, sizeof(dp));

	dp[N] = true;

	int e;

	while (cin >> e)
		dp[e] = false;

	bool ans = false;

	for (int now = 1; now <= K; ++now)
		ans |= canWin(now);

	cout << ans << '\n';

	return 0;
}
