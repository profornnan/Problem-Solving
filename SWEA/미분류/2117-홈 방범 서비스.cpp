#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Pos {
	int y;
	int x;
};

int dx[]{ 1, 0, -1, 0 };
int dy[]{ 0, -1, 0, 1 };

int N, M;
int MAP[20][20];
int cost[45];
int ans;
int totalHome;

void bfs(int sy, int sx) {
	queue<Pos> q;
	int visited[20][20]{};

	q.push({ sy, sx });
	visited[sy][sx] = 1;

	int K = 1;
	int home = 0;

	while (!q.empty()) {
		int sz = q.size();

		while (sz--) {
			Pos now = q.front();
			q.pop();

			if (MAP[now.y][now.x] == 1)
				home++;

			for (int i = 0; i < 4; i++) {
				int ny = now.y + dy[i];
				int nx = now.x + dx[i];

				if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
				if (visited[ny][nx] != 0) continue;

				q.push({ ny, nx });
				visited[ny][nx] = 1;
			}
		}

		if (M * home - cost[K] >= 0)
			ans = max(ans, home);

		if (home == totalHome)
			break;

		K++;
	}
}

int main(void) {
	int T;
	cin >> T;

	for (int i = 1; i < 45; i++)
		cost[i] = i * i + (i - 1) * (i - 1);

	for (int tc = 1; tc <= T; tc++) {
		cout << '#' << tc << ' ';

		ans = 0;
		totalHome = 0;

		cin >> N >> M;

		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				cin >> MAP[y][x];
				if (MAP[y][x] == 1)
					totalHome++;
			}
		}

		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++)
				bfs(y, x);

		cout << ans << '\n';
	}

	return 0;
}
