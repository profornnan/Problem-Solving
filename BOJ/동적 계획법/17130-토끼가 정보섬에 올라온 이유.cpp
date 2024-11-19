#include <iostream>
#include <algorithm>
using namespace std;

constexpr int MAX_N = 1'000;
constexpr int MAX_M = 1'000;
constexpr int dy[]{ 1, 0, -1 };

enum {
	EMPTY = '.',
	WALL = '#',
	START = 'R',
	CARROT = 'C',
	END = 'O'
};

int N, M;
char MAP[MAX_N][MAX_M];
int dp[MAX_N][MAX_M];
int sy, sx;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> M;

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			cin >> MAP[y][x];

			if (MAP[y][x] == START) {
				sy = y;
				sx = x;
			}
		}
	}

	dp[sy][sx] = 1;

	for (int x = sx; x < M - 1; ++x) {
		for (int y = 0; y < N; ++y) {
			if (!dp[y][x])
				continue;

			for (int dir = 0; dir < 3; ++dir) {
				const int ny = y + dy[dir];
				const int nx = x + 1;

				if (ny < 0 || ny >= N)
					continue;

				if (MAP[ny][nx] == WALL)
					continue;

				dp[ny][nx] = max(dp[ny][nx], dp[y][x] + (MAP[ny][nx] == CARROT));
			}
		}
	}

	int ans = 0;

	for (int y = 0; y < N; ++y)
		for (int x = sx; x < M; ++x)
			if (MAP[y][x] == END)
				ans = max(ans, dp[y][x]);

	cout << ans - 1 << '\n';

	return 0;
}
