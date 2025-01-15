#include <iostream>
#include <algorithm>
using namespace std;

constexpr int MOD = 1'000'000'007;
constexpr int MAX_N = 3'000;

int N, K;
long long dp[MAX_N + 2][2];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> K;

	dp[0][0] = 1;

	for (int i = 1; i <= N + 1; ++i) {
		for (int j = 1; j <= min(i, K); ++j) {
			dp[i][0] = (dp[i][0] + dp[i - j][0]) % MOD;
			dp[i][1] = (dp[i][1] + dp[i - j][1]) % MOD;
		}

		if (i >= K + 1) {
			dp[i][1] = (dp[i][1] + dp[i - K - 1][0]) % MOD;
			dp[i][1] = (dp[i][1] + dp[i - K - 1][1]) % MOD;
		}
	}

	cout << dp[N + 1][1] << '\n';

	return 0;
}
