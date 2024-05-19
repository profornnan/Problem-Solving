#include <iostream>
#include <queue>
using namespace std;

constexpr int MAX_N = 50;
constexpr int MAX_M = 50;
constexpr int dx[]{ 1, 0, -1, 0 };
constexpr int dy[]{ 0, -1, 0, 1 };

enum {
	EMPTY = '.',
	SPOT = 'X'
};

struct Pos {
	int y;
	int x;
};

int N, M;
char MAP[MAX_N][MAX_M];
bool visited[MAX_N][MAX_M];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> M;

	Pos st;

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			cin >> MAP[y][x];

			if (MAP[y][x] == SPOT)
				st = { y, x };
		}
	}

	queue<Pos> q;
	queue<Pos> border;

	q.push(st);
	visited[st.y][st.x] = true;

	while (!q.empty()) {
		const auto [y, x] = q.front();
		q.pop();

		for (int dir = 0; dir < 4; ++dir) {
			const int ny = y + dy[dir];
			const int nx = x + dx[dir];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue;

			if (visited[ny][nx])
				continue;

			visited[ny][nx] = true;
			MAP[ny][nx] == SPOT ? q.push({ ny, nx }) : border.push({ ny, nx });
		}
	}

	int cnt = 0;

	while (!border.empty()) {
		int sz = border.size();

		while (sz--) {
			const auto [y, x] = border.front();
			border.pop();

			if (MAP[y][x] == SPOT) {
				cout << cnt << '\n';
				return 0;
			}

			for (int dir = 0; dir < 4; ++dir) {
				const int ny = y + dy[dir];
				const int nx = x + dx[dir];

				if (ny < 0 || ny >= N || nx < 0 || nx >= M)
					continue;

				if (visited[ny][nx])
					continue;

				visited[ny][nx] = true;
				border.push({ ny, nx });
			}
		}

		++cnt;
	}

	return 0;
}
