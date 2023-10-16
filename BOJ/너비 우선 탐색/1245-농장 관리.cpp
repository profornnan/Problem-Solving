#include <iostream>
#include <queue>
using namespace std;
using pii = pair<int, int>;

constexpr int MAX_N = 100;
constexpr int MAX_M = 70;

constexpr int dx[]{ 1, 1, 0, -1, -1, -1, 0, 1 };
constexpr int dy[]{ 0, -1, -1, -1, 0, 1, 1, 1 };

int N, M;
int MAP[MAX_N][MAX_M];
bool visited[MAX_N][MAX_M];
int ans;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> M;

	for (int y = 0; y < N; ++y)
		for (int x = 0; x < M; ++x)
			cin >> MAP[y][x];

	for (int sy = 0; sy < N; ++sy) {
		for (int sx = 0; sx < M; ++sx) {
			const int height = MAP[sy][sx];

			if (visited[sy][sx])
				continue;

			queue<pii> q;
			bool isPeak = true;

			visited[sy][sx] = true;
			q.push({ sy, sx });

			while (!q.empty()) {
				const auto [y, x] = q.front();
				q.pop();

				for (int dir = 0; dir < 8; ++dir) {
					int ny = y + dy[dir];
					int nx = x + dx[dir];

					if (ny < 0 || ny >= N || nx < 0 || nx >= M)
						continue;

					if (MAP[ny][nx] > height) {
						isPeak = false;
						continue;
					}

					if (MAP[ny][nx] < height)
						continue;

					if (visited[ny][nx])
						continue;

					visited[ny][nx] = true;
					q.push({ ny, nx });
				}
			}

			if (isPeak)
				++ans;
		}
	}

	cout << ans << '\n';

	return 0;
}
