#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

constexpr int MAX_N = 1'000;
constexpr int MAX_M = 1'000;
constexpr int dx[]{ 1, 0, -1, 0 };
constexpr int dy[]{ 0, -1, 0, 1 };

enum {
	EMPTY = '.',
	WALL = '#',
	ICE = '_',
	END = 'M'
};

struct Pos {
	int y;
	int x;
};

int N, M;
char MAP[MAX_N][MAX_M];
int visited[MAX_N][MAX_M];
Pos en;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> M >> N;

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			cin >> MAP[y][x];

			if (MAP[y][x] == END) {
				MAP[y][x] = EMPTY;
				en = { y, x };
			}
		}
	}

	queue<Pos> q;
	memset(visited, -1, sizeof(visited));

	q.push(en);
	visited[en.y][en.x] = 0;

	while (!q.empty()) {
		const auto [y, x] = q.front();
		q.pop();

		for (int dir = 0; dir < 4; ++dir) {
			const int opp = (dir + 2) % 4;

			if (MAP[y][x] == ICE && MAP[y + dy[opp]][x + dx[opp]] != WALL)
				continue;

			int ny = y + dy[dir];
			int nx = x + dx[dir];

			while (true) {
				if (MAP[ny][nx] == WALL)
					break;

				if (visited[ny][nx] == -1) {
					q.push({ ny, nx });
					visited[ny][nx] = visited[y][x] + 1;
				}

				if (MAP[ny][nx] == EMPTY)
					break;

				ny += dy[dir];
				nx += dx[dir];
			}
		}
	}

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x)
			cout << visited[y][x] << ' ';
		cout << '\n';
	}

	return 0;
}
