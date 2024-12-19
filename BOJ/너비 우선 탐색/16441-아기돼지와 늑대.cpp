#include <iostream>
#include <queue>
using namespace std;

constexpr int MAX_N = 100;
constexpr int MAX_M = 100;
constexpr int dx[]{ 1, 0, -1, 0 };
constexpr int dy[]{ 0, -1, 0, 1 };

enum {
	GROUND = '.',
	ICE = '+',
	MOUNTAIN = '#',
	WOLF = 'W'
};

int N, M;
char MAP[MAX_N][MAX_M];
bool visited[MAX_N][MAX_M];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> M;

	queue<pair<int, int>> q;

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			cin >> MAP[y][x];

			if (MAP[y][x] == WOLF) {
				q.push({ y, x });
				visited[y][x] = true;
			}
		}
	}

	while (!q.empty()) {
		const auto [y, x] = q.front();
		q.pop();

		for (int dir = 0; dir < 4; ++dir) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			if (MAP[ny][nx] == MOUNTAIN)
				continue;

			while (MAP[ny][nx] != GROUND && MAP[ny + dy[dir]][nx + dx[dir]] != MOUNTAIN) {
				ny += dy[dir];
				nx += dx[dir];
			}

			if (visited[ny][nx])
				continue;

			q.push({ ny, nx });
			visited[ny][nx] = true;
		}
	}

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x)
			cout << (MAP[y][x] == GROUND && !visited[y][x] ? 'P' : MAP[y][x]);
		cout << '\n';
	}

	return 0;
}
