#include <iostream>
#include <cstring>
using namespace std;

int N, R, G, B;
long long dp[11][101][101][101];
int C[11][11];

int Combination(int n, int r) {
	if (r == 0 || n == r)
		return 1;

	if (C[n][r] != -1)
		return C[n][r];

	return C[n][r] = Combination(n - 1, r - 1) + Combination(n - 1, r);
}

long long dfs(int level, int r, int g, int b) {
	if (level >= N + 1)
		return 1;

	if (dp[level][r][g][b] != -1)
		return dp[level][r][g][b];

	long long ret = 0;

	if (level <= r)
		ret += dfs(level + 1, r - level, g, b);

	if (level <= g)
		ret += dfs(level + 1, r, g - level, b);

	if (level <= b)
		ret += dfs(level + 1, r, g, b - level);

	if (level % 2 == 0) {
		int len = level / 2;

		if (len <= r && len <= g)
			ret += dfs(level + 1, r - len, g - len, b) * Combination(level, len);

		if (len <= r && len <= b)
			ret += dfs(level + 1, r - len, g, b - len) * Combination(level, len);

		if (len <= g && len <= b)
			ret += dfs(level + 1, r, g - len, b - len) * Combination(level, len);
	}

	if (level % 3 == 0) {
		int len = level / 3;

		if (len <= r && len <= g && len <= b)
			ret += dfs(level + 1, r - len, g - len, b - len) * Combination(level, len) * Combination(level - len, len) * Combination(level - 2 * len, len);
	}

	return dp[level][r][g][b] = ret;
}

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> N >> R >> G >> B;

	memset(C, -1, sizeof(C));
	memset(dp, -1, sizeof(dp));

	cout << dfs(1, R, G, B) << '\n';

	return 0;
}
