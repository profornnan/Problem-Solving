#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

constexpr int MAX_N = 50;
constexpr int MAX_M = 50;
constexpr int dx[]{ 1, 0, -1, 0 };
constexpr int dy[]{ 0, -1, 0, 1 };

int N, M;
int MAP[MAX_N][MAX_M];
int visited[MAX_N][MAX_M];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> M;

	for (int y = 0; y < N; ++y)
		for (int x = 0; x < M; ++x)
			cin >> MAP[y][x];

	int maxDist = 0;
	int ans = 0;

	for (int sy = 0; sy < N; ++sy) {
		for (int sx = 0; sx < M; ++sx) {
			if (!MAP[sy][sx])
				continue;

			queue<pair<int, int>> q;
			memset(visited, 0, sizeof(visited));

			q.push({ sy, sx });
			visited[sy][sx] = 1;

			while (!q.empty()) {
				const auto [y, x] = q.front();
				q.pop();

				for (int dir = 0; dir < 4; ++dir) {
					int ny = y + dy[dir];
					int nx = x + dx[dir];

					if (ny < 0 || ny >= N || nx < 0 || nx >= M)
						continue;

					if (!MAP[ny][nx])
						continue;

					if (visited[ny][nx])
						continue;

					q.push({ ny, nx });
					visited[ny][nx] = visited[y][x] + 1;

					if (maxDist < visited[ny][nx]) {
						maxDist = visited[ny][nx];
						ans = MAP[sy][sx] + MAP[ny][nx];
					}
					else if (maxDist == visited[ny][nx])
						ans = max(ans, MAP[sy][sx] + MAP[ny][nx]);
				}
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
