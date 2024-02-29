#include <iostream>
#include <queue>
using namespace std;

constexpr int MAX_N = 50;
constexpr int MAX_M = 50;
constexpr int MAX_C = 5;
constexpr int dx[]{ 1, 0, -1, 0 };
constexpr int dy[]{ 0, -1, 0, 1 };

struct Pos {
	int y;
	int x;

	bool operator==(const Pos& rhs) const {
		return y == rhs.y && x == rhs.x;
	}
};

struct Node {
	Pos pos;
	int state;
};

int N, M, C;
char MAP[MAX_N][MAX_M];
int visited[MAX_N][MAX_M][1 << MAX_C];
Pos st, en;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> M >> N;

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			cin >> MAP[y][x];

			if (MAP[y][x] == 'S')
				st = { y, x };
			else if (MAP[y][x] == 'E')
				en = { y, x };
			else if (MAP[y][x] == 'X')
				MAP[y][x] = C++;
		}
	}

	queue<Node> q;
	q.push({ st, 0 });
	visited[st.y][st.x][0] = 1;

	while (!q.empty()) {
		const auto [now, state] = q.front();
		q.pop();

		if (now == en && state == (1 << C) - 1) {
			cout << visited[now.y][now.x][state] - 1 << '\n';
			return 0;
		}

		for (int dir = 0; dir < 4; ++dir) {
			int ny = now.y + dy[dir];
			int nx = now.x + dx[dir];
			int nstate = state;

			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue;

			if (MAP[ny][nx] == '#')
				continue;

			if (MAP[ny][nx] >= 0 && MAP[ny][nx] < C)
				nstate |= (1 << MAP[ny][nx]);

			if (visited[ny][nx][nstate])
				continue;

			q.push({ { ny, nx }, nstate });
			visited[ny][nx][nstate] = visited[now.y][now.x][state] + 1;
		}
	}

	return 0;
}
