#include <iostream>
using namespace std;

constexpr int MOD = 1'000;
constexpr int MAX_N = 1'000'000;

int A, B, D, N;
int dp[MAX_N + 1];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> A >> B >> D >> N;

	dp[0] = 1;

	for (int i = 1; i < A; ++i)
		dp[i] = 1;

	for (int i = A; i <= N; ++i) {
		dp[i] = (dp[i - 1] + dp[i - A]) % MOD;

		if (i - B >= 0)
			dp[i] = (dp[i] - dp[i - B] + MOD) % MOD;
	}

	int ans = dp[N];

	if (N - D >= 0)
		ans = (ans - dp[N - D] + MOD) % MOD;

	cout << ans << '\n';

	return 0;
}
