#include <iostream>
#include <vector>
#include <queue>
using namespace std;

constexpr int MAX_N = 100;

constexpr int dx[]{ 1, 0, -1, 0 };
constexpr int dy[]{ 0, -1, 0, 1 };

struct Pos {
	int y;
	int x;
};

enum {
	OFF,
	ON,
	ADJ
};

int MAP[MAX_N + 1][MAX_N + 1];
bool visited[MAX_N + 1][MAX_N + 1];
vector<Pos> btn[MAX_N + 1][MAX_N + 1];
int cnt;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; ++i) {
		int y, x, ny, nx;
		cin >> y >> x >> ny >> nx;
		btn[y][x].push_back({ ny, nx });
	}

	queue<Pos> q;

	q.push({ 1, 1 });
	visited[1][1] = true;

	++cnt;
	MAP[1][1] = ON;

	while (!q.empty()) {
		auto [y, x] = q.front();
		q.pop();

		for (const auto& [ny, nx] : btn[y][x]) {
			if (MAP[ny][nx] == ON)
				continue;

			if (MAP[ny][nx] == ADJ) {
				q.push({ ny, nx });
				visited[ny][nx] = true;
			}

			++cnt;
			MAP[ny][nx] = ON;
		}

		for (int dir = 0; dir < 4; ++dir) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			if (ny < 1 || ny >= N + 1 || nx < 1 || nx >= N + 1)
				continue;

			if (MAP[ny][nx] != ON) {
				MAP[ny][nx] = ADJ;
				continue;
			}

			if (visited[ny][nx])
				continue;

			q.push({ ny, nx });
			visited[ny][nx] = true;
		}
	}

	cout << cnt << '\n';

	return 0;
}
