#include <iostream>
#include <vector>
#include <queue>
using namespace std;

constexpr int MAX_N = 50;
constexpr int dx[]{ 1, 0, -1, 0 };
constexpr int dy[]{ 0, -1, 0, 1 };
constexpr int MASK = (1 << 2) - 1;

struct Pos {
	int y;
	int x;
};

struct Node {
	Pos pos;
	int dir;
	int state;
};

char MAP[MAX_N][MAX_N];
int visited[MAX_N][MAX_N][4][1 << 2];
Pos st;
vector<Pos> dest;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			cin >> MAP[y][x];

			if (MAP[y][x] == 'S')
				st = { y, x };
			else if (MAP[y][x] == 'C')
				dest.push_back({ y, x });
		}
	}

	queue<Node> q;

	for (int dir = 0; dir < 4; ++dir) {
		q.push({ st.y, st.x, dir, 0 });
		visited[st.y][st.x][dir][0] = 1;
	}

	while (!q.empty()) {
		const auto [pos, dir, state] = q.front();
		q.pop();

		int nstate = state;

		for (int i = 0; i < 2; ++i)
			if (pos.y == dest[i].y && pos.x == dest[i].x)
				nstate |= (1 << i);

		if (nstate == MASK) {
			cout << visited[pos.y][pos.x][dir][state] - 1 << '\n';
			return 0;
		}

		for (int ndir = 0; ndir < 4; ++ndir) {
			if (dir == ndir)
				continue;

			int ny = pos.y + dy[ndir];
			int nx = pos.x + dx[ndir];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue;

			if (MAP[ny][nx] == '#')
				continue;

			if (visited[ny][nx][ndir][nstate])
				continue;

			q.push({ ny, nx, ndir, nstate });
			visited[ny][nx][ndir][nstate] = visited[pos.y][pos.x][dir][state] + 1;
		}
	}

	cout << "-1\n";

	return 0;
}
