#include <iostream>
#include <cstring>
using namespace std;

constexpr int MOD = 1'000'000'007;
constexpr int MAX_S = 50;

int dp[MAX_S + 1][MAX_S + 1][MAX_S + 1][MAX_S + 1];

int dfs(int s, int d, int k, int h) {
	if (d < 0 || k < 0 || h < 0)
		return 0;

	if (s == 0)
		return d == 0 && k == 0 && h == 0 ? 1 : 0;

	int& ret = dp[s][d][k][h];

	if (ret != -1)
		return ret;

	ret = 0;

	ret = (ret + dfs(s - 1, d - 1, k, h)) % MOD;
	ret = (ret + dfs(s - 1, d, k - 1, h)) % MOD;
	ret = (ret + dfs(s - 1, d, k, h - 1)) % MOD;

	ret = (ret + dfs(s - 1, d - 1, k - 1, h)) % MOD;
	ret = (ret + dfs(s - 1, d - 1, k, h - 1)) % MOD;
	ret = (ret + dfs(s - 1, d, k - 1, h - 1)) % MOD;

	ret = (ret + dfs(s - 1, d - 1, k - 1, h - 1)) % MOD;

	return ret;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int S, D, K, H;
	cin >> S >> D >> K >> H;

	memset(dp, -1, sizeof(dp));

	cout << dfs(S, D, K, H) << '\n';

	return 0;
}
