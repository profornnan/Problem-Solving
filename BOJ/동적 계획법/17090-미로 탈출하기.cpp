#include <iostream>
#include <cstring>
using namespace std;

constexpr int MAX_N = 500;
constexpr int MAX_M = 500;

int N, M;
char MAP[MAX_N][MAX_M];
int dp[MAX_N][MAX_M];

int dfs(const int y, const int x) {
	if (y < 0 || y >= N || x < 0 || x >= M)
		return 1;

	int& ret = dp[y][x];

	if (ret != -1)
		return ret;

	ret = 0;

	const char ch = MAP[y][x];

	if (ch == 'R') ret = dfs(y, x + 1);
	else if (ch == 'U') ret = dfs(y - 1, x);
	else if (ch == 'L') ret = dfs(y, x - 1);
	else if (ch == 'D') ret = dfs(y + 1, x);

	return ret;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> M;

	for (int y = 0; y < N; ++y)
		for (int x = 0; x < M; ++x)
			cin >> MAP[y][x];

	memset(dp, -1, sizeof(dp));

	int ans = 0;

	for (int y = 0; y < N; ++y)
		for (int x = 0; x < M; ++x)
			ans += dfs(y, x);

	cout << ans << '\n';

	return 0;
}
