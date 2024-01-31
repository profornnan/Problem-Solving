#include <iostream>
#include <queue>
using namespace std;

constexpr int MAX_N = 100;
constexpr int MAX_M = 100;
constexpr int dx[]{ 1, 0, -1, 0 };
constexpr int dy[]{ 0, -1, 0, 1 };
constexpr int input2dir[]{ 0, 0, 2, 3, 1 };

struct Robot {
	int y;
	int x;
	int dir;
};

int N, M;
int MAP[MAX_N][MAX_M];
int visited[MAX_N][MAX_M][4];
Robot st, en;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> M;

	for (int y = 0; y < N; ++y)
		for (int x = 0; x < M; ++x)
			cin >> MAP[y][x];

	cin >> st.y >> st.x >> st.dir;
	--st.y; --st.x;
	st.dir = input2dir[st.dir];

	cin >> en.y >> en.x >> en.dir;
	--en.y; --en.x;
	en.dir = input2dir[en.dir];

	queue<Robot> q;
	q.push(st);
	visited[st.y][st.x][st.dir] = 1;

	while (!q.empty()) {
		const auto [y, x, dir] = q.front();
		q.pop();

		// Go
		for (int k = 1; k <= 3; ++k) {
			int ny = y + dy[dir] * k;
			int nx = x + dx[dir] * k;

			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				break;

			if (MAP[ny][nx] == 1)
				break;

			if (visited[ny][nx][dir])
				continue;

			q.push({ ny, nx, dir });
			visited[ny][nx][dir] = visited[y][x][dir] + 1;
		}

		// Turn
		for (int i = 1; i <= 3; i += 2) {
			int ndir = (dir + i) % 4;

			if (visited[y][x][ndir])
				continue;

			q.push({ y, x, ndir });
			visited[y][x][ndir] = visited[y][x][dir] + 1;
		}
	}

	cout << visited[en.y][en.x][en.dir] - 1 << '\n';

	return 0;
}
