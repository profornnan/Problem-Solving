#include <iostream>
#include <string>
#include <cstring>
using namespace std;

constexpr int MAX_N = 100;
constexpr int MAX_M = 100;
constexpr int MAX_L = 80;
constexpr int dx[]{ 1, 0, -1, 0 };
constexpr int dy[]{ 0, -1, 0, 1 };

int N, M, K;
char MAP[MAX_N][MAX_M];
int dp[MAX_N][MAX_M][MAX_L];
string str;

int dfs(int y, int x, int len) {
	if (len >= str.size())
		return 1;

	int& ret = dp[y][x][len];

	if (ret != -1)
		return ret;

	ret = 0;

	for (int dir = 0; dir < 4; ++dir) {
		int ny = y;
		int nx = x;

		for (int k = 0; k < K; ++k) {
			ny += dy[dir];
			nx += dx[dir];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				break;

			if (MAP[ny][nx] == str[len])
				ret += dfs(ny, nx, len + 1);
		}
	}

	return ret;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> M >> K;

	for (int y = 0; y < N; ++y)
		for (int x = 0; x < M; ++x)
			cin >> MAP[y][x];

	cin >> str;

	memset(dp, -1, sizeof(dp));

	int ans = 0;

	for (int y = 0; y < N; ++y)
		for (int x = 0; x < M; ++x)
			if (MAP[y][x] == str[0])
				ans += dfs(y, x, 1);

	cout << ans << '\n';

	return 0;
}
