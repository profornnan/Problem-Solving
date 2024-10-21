#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

constexpr int MAX_D = 100;
constexpr int dx[]{ 2, 1, -1, -2, -1, 1 };
constexpr int dy[]{ 0, -1, -1, 0, 1, 1 };

enum {
	EMPTY = ' ',
	WATER = 'W',
	LAND = 'L',
	FOOD = 'F'
};

int T, D, N, M;
string MAP[MAX_D * 2 - 1];
bool visited[MAX_D * 2 - 1][MAX_D * 4 - 3];

int bfs(const int sy, const int sx) {
	int cnt = 0;
	queue<pair<int, int>> q;

	q.push({ sy, sx });
	visited[sy][sx] = true;

	while (!q.empty()) {
		const auto [y, x] = q.front();
		q.pop();

		if (MAP[y][x] == FOOD)
			++cnt;

		for (int dir = 0; dir < 6; ++dir) {
			const int ny = y + dy[dir];
			const int nx = x + dx[dir];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue;

			if (visited[ny][nx])
				continue;

			if (MAP[ny][nx] == EMPTY)
				continue;

			if (MAP[ny][nx] == WATER)
				continue;

			q.push({ ny, nx });
			visited[ny][nx] = true;
		}
	}

	return cnt;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cin >> D;
		cin.ignore();

		N = D * 2 - 1;
		M = D * 4 - 3;

		for (int y = 0; y < N; ++y)
			getline(cin, MAP[y]);

		int ans = 0;
		queue<pair<int, int>> q;
		memset(visited, false, sizeof(visited));

		q.push({ D - 1, (D - 1) * 2 });
		visited[D - 1][(D - 1) * 2] = true;

		while (!q.empty()) {
			const auto [y, x] = q.front();
			q.pop();

			for (int dir = 0; dir < 6; ++dir) {
				const int ny = y + dy[dir];
				const int nx = x + dx[dir];

				if (ny < 0 || ny >= N || nx < 0 || nx >= M)
					continue;

				if (visited[ny][nx])
					continue;

				if (MAP[ny][nx] == EMPTY)
					continue;

				if (MAP[ny][nx] != WATER) {
					ans = max(ans, bfs(ny, nx));
					continue;
				}

				q.push({ ny, nx });
				visited[ny][nx] = true;
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
