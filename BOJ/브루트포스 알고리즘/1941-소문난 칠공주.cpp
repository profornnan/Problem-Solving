#include <iostream>
#include <queue>
using namespace std;

constexpr int N = 5;
constexpr int dx[]{ 1, 0, -1, 0 };
constexpr int dy[]{ 0, -1, 0, 1 };

int ans;
char MAP[N][N];
bool selected[N][N];

void dfs(int sCnt, int yCnt, int prev) {
	if (sCnt + yCnt >= 7) {
		if (sCnt < yCnt)
			return;

		const int sy = prev / N;
		const int sx = prev % N;

		int cnt = 0;
		queue<pair<int, int>> q;
		bool visited[N][N]{};

		q.push({ sy, sx });
		visited[sy][sx] = true;

		while (!q.empty()) {
			const auto [y, x] = q.front();
			q.pop();
			++cnt;

			for (int dir = 0; dir < 4; ++dir) {
				int ny = y + dy[dir];
				int nx = x + dx[dir];

				if (ny < 0 || ny >= N || nx < 0 || nx >= N)
					continue;

				if (!selected[ny][nx] || visited[ny][nx])
					continue;

				q.push({ ny, nx });
				visited[ny][nx] = true;
			}
		}

		if (cnt == 7)
			++ans;

		return;
	}

	for (int now = prev + 1; now < N * N; ++now) {
		const int y = now / N;
		const int x = now % N;

		selected[y][x] = true;
		dfs(sCnt + (MAP[y][x] == 'S'), yCnt + (MAP[y][x] == 'Y'), now);
		selected[y][x] = false;
	}
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	for (int y = 0; y < N; ++y)
		for (int x = 0; x < N; ++x)
			cin >> MAP[y][x];

	dfs(0, 0, -1);

	cout << ans << '\n';

	return 0;
}
