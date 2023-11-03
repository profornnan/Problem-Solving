#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

constexpr int MAX_N = 500;
constexpr int dx[]{ 1, 0, -1, 0 };
constexpr int dy[]{ 0, -1, 0, 1 };

int N;
int MAP[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];

int dfs(int y, int x) {
	int& ret = dp[y][x];

	if (ret != -1)
		return ret;

	ret = 1;

	for (int dir = 0; dir < 4; ++dir) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if (ny < 0 || ny >= N || nx < 0 || nx >= N)
			continue;

		if (MAP[y][x] >= MAP[ny][nx])
			continue;

		ret = max(ret, dfs(ny, nx) + 1);
	}

	return ret;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	for (int y = 0; y < N; ++y)
		for (int x = 0; x < N; ++x)
			cin >> MAP[y][x];

	memset(dp, -1, sizeof(dp));

	int ans = 0;

	for (int y = 0; y < N; ++y)
		for (int x = 0; x < N; ++x)
			ans = max(ans, dfs(y, x));

	cout << ans << '\n';

	return 0;
}
