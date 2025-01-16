#include <iostream>
#include <queue>
using namespace std;

constexpr int MAX_N = 100;
constexpr int MAX_M = 100;
constexpr int dx[]{ 1, 0, -1, 0 };
constexpr int dy[]{ 0, -1, 0, 1 };

enum {
	START = -3,
	END = -2,
	WALL = -1,
	EMPTY = 0
};

struct Node {
	int y;
	int x;
	int level;

	bool operator<(const Node& rhs) const {
		return rhs.level < level;
	}
};

int N, M, L, E, K;
int MAP[MAX_N][MAX_M];
bool visited[MAX_N][MAX_M];
int sy, sx, ey, ex;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> M >> L >> E >> K;

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			cin >> MAP[y][x];

			if (MAP[y][x] == START) {
				MAP[y][x] = EMPTY;
				sy = y;
				sx = x;
			}
			else if (MAP[y][x] == END) {
				MAP[y][x] = K - 1;
				ey = y;
				ex = x;
			}
		}
	}

	priority_queue<Node> pq;

	pq.push({ sy, sx, MAP[sy][sx] });
	visited[sy][sx] = true;

	while (!pq.empty() && pq.top().level < L) {
		const auto [y, x, level] = pq.top();
		pq.pop();

		if (y == ey && x == ex) {
			cout << "O\n";
			return 0;
		}

		E += level;

		while (L <= E) {
			E -= L;
			++L;
		}

		for (int dir = 0; dir < 4; ++dir) {
			const int ny = y + dy[dir];
			const int nx = x + dx[dir];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue;

			if (visited[ny][nx])
				continue;

			if (MAP[ny][nx] == WALL)
				continue;

			pq.push({ ny, nx, MAP[ny][nx] });
			visited[ny][nx] = true;
		}
	}

	cout << "X\n";

	return 0;
}
