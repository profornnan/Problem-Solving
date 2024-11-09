#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

constexpr int MAX_N = 2'000;
constexpr int MAX_M = 2'000;
constexpr int dx[] = { 1, 0, -1, 0 };
constexpr int dy[] = { 0, -1, 0, 1 };

enum {
	EMPTY = 0,
	WALL = 1,
	CHAIR = 2,
	DOLL = 3,
	START = 4
};

struct Pos {
	int y;
	int x;
};

int N, M, K;
int MAP[MAX_N][MAX_M];
int visited[MAX_N][MAX_M];
Pos st;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> M >> K;

	queue<Pos> q;

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			int& c = MAP[y][x];
			cin >> c;

			if (c == DOLL) {
				q.push({ y, x });
				visited[y][x] = 1;
			}
			else if (c == START)
				st = { y, x };
		}
	}

	for (int k = 0; k <= K; ++k) {
		int sz = q.size();

		while (sz--) {
			const auto [y, x] = q.front();
			q.pop();

			MAP[y][x] = DOLL;

			for (int dir = 0; dir < 4; ++dir) {
				const int ny = y + dy[dir];
				const int nx = x + dx[dir];

				if (ny < 0 || ny >= N || nx < 0 || nx >= M)
					continue;

				if (visited[ny][nx])
					continue;

				q.push({ ny, nx });
				visited[ny][nx] = 1;
			}
		}
	}

	queue<Pos>().swap(q);
	memset(visited, 0, sizeof(visited));

	q.push(st);
	visited[st.y][st.x] = 1;

	while (!q.empty()) {
		const auto [y, x] = q.front();
		q.pop();

		if (MAP[y][x] == CHAIR) {
			cout << visited[y][x] - 1 << '\n';
			return 0;
		}

		for (int dir = 0; dir < 4; ++dir) {
			const int ny = y + dy[dir];
			const int nx = x + dx[dir];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue;

			if (visited[ny][nx])
				continue;

			if (MAP[ny][nx] == WALL || MAP[ny][nx] == DOLL)
				continue;

			q.push({ ny, nx });
			visited[ny][nx] = visited[y][x] + 1;
		}
	}

	cout << "-1\n";

	return 0;
}
