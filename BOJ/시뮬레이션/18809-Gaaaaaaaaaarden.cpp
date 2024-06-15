#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

constexpr int MAX_N = 50;
constexpr int MAX_M = 50;
constexpr int MAX_C = 10;
constexpr int dx[]{ 1, 0, -1, 0 };
constexpr int dy[]{ 0, -1, 0, 1 };

enum {
	LAKE,
	GROUND,
	CANDIDATE
};

enum {
	EMPTY,
	GREEN,
	RED,
	FLOWER
};

struct Point {
	int y;
	int x;
};

int N, M, G, R, ans;
int garden[MAX_N][MAX_M];
int visited[MAX_N][MAX_M];
int time[MAX_N][MAX_M];
int path[MAX_C];
int color[MAX_C];
vector<Point> candidates;

void dfs(const int level, const int prev, const int gcnt, const int rcnt) {
	if (level >= G + R) {
		int cnt = 0;
		int t = 0;

		queue<Point> q;
		memset(visited, 0, sizeof(visited));
		memset(time, -1, sizeof(time));

		for (int i = 0; i < G + R; ++i) {
			const Point p = candidates[path[i]];
			q.push(p);
			visited[p.y][p.x] = color[i];
			time[p.y][p.x] = t;
		}

		while (!q.empty()) {
			int sz = q.size();
			++t;

			while (sz--) {
				const auto [y, x] = q.front();
				q.pop();

				if (visited[y][x] == FLOWER)
					continue;

				for (int dir = 0; dir < 4; ++dir) {
					int ny = y + dy[dir];
					int nx = x + dx[dir];

					if (ny < 0 || ny >= N || nx < 0 || nx >= M)
						continue;

					if (garden[ny][nx] == LAKE)
						continue;

					if (visited[ny][nx] == FLOWER)
						continue;

					if (visited[ny][nx]) {
						if (visited[ny][nx] != visited[y][x] && time[ny][nx] == t) {
							visited[ny][nx] = FLOWER;
							++cnt;
						}

						continue;
					}

					q.push({ ny, nx });
					visited[ny][nx] = visited[y][x];
					time[ny][nx] = t;
				}
			}
		}

		ans = ans > cnt ? ans : cnt;

		return;
	}

	for (int now = prev + 1; now < candidates.size(); ++now) {
		path[level] = now;

		if (gcnt < G) {
			color[level] = GREEN;
			dfs(level + 1, now, gcnt + 1, rcnt);
		}

		if (rcnt < R) {
			color[level] = RED;
			dfs(level + 1, now, gcnt, rcnt + 1);
		}
	}
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> M >> G >> R;

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			cin >> garden[y][x];

			if (garden[y][x] == CANDIDATE)
				candidates.push_back({ y, x });
		}
	}

	dfs(0, -1, 0, 0);

	cout << ans << '\n';

	return 0;
}
