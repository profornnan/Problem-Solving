#include <iostream>
#include <queue>
using namespace std;

constexpr int MAX_N = 1'000;
constexpr int MAX_M = 1'000;
constexpr int dx[]{ 1, 0, -1, 0 };
constexpr int dy[]{ 0, -1, 0, 1 };

enum { EMPTY, WALL };

struct Pos {
	int y;
	int x;
};

struct Node {
	Pos pos;
	bool breakWall;
	int cost;
};

int N, M;
Pos st, en;
int MAP[MAX_N][MAX_M];
bool visited[MAX_N][MAX_M][2];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> M;
	cin >> st.y >> st.x >> en.y >> en.x;

	--st.y; --st.x;
	--en.y; --en.x;

	for (int y = 0; y < N; ++y)
		for (int x = 0; x < M; ++x)
			cin >> MAP[y][x];

	queue<Node> q;

	q.push({ st, 0, 0 });
	visited[st.y][st.x][0] = true;

	while (!q.empty()) {
		const auto [pos, breakWall, cost] = q.front();
		q.pop();

		if (pos.y == en.y && pos.x == en.x) {
			cout << cost << '\n';
			return 0;
		}

		for (int dir = 0; dir < 4; ++dir) {
			int ny = pos.y + dy[dir];
			int nx = pos.x + dx[dir];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue;

			if (MAP[ny][nx] == WALL && breakWall)
				continue;

			bool nbreakWall = breakWall || MAP[ny][nx] == WALL;

			if (visited[ny][nx][nbreakWall])
				continue;

			q.push({ { ny, nx }, nbreakWall, cost + 1 });
			visited[ny][nx][nbreakWall] = true;
		}
	}

	cout << "-1\n";

	return 0;
}
