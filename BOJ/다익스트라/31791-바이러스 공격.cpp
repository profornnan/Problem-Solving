#include <iostream>
#include <queue>
using namespace std;

constexpr int INF = 21e8;
constexpr int MAX_N = 1'000;
constexpr int MAX_M = 1'000;
constexpr int dx[]{ 1, 0, -1, 0 };
constexpr int dy[]{ 0, -1, 0, 1 };

enum {
	EMPTY = '.',
	BUILDING = '#',
	VIRUS = '*'
};

struct Node {
	int y;
	int x;
	int cost;

	bool operator<(const Node& rhs) const {
		return cost > rhs.cost;
	}
};

int N, M, TE, TB, V, B;
char MAP[MAX_N][MAX_M];
int dist[MAX_N][MAX_M];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> M >> TE >> TB >> V >> B;

	priority_queue<Node> pq;

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			cin >> MAP[y][x];
			dist[y][x] = INF;

			if (MAP[y][x] == VIRUS) {
				pq.push({ y, x, 0 });
				dist[y][x] = 0;
			}
		}
	}

	while (!pq.empty() && pq.top().cost < TE) {
		const auto [y, x, cost] = pq.top();
		pq.pop();

		if (dist[y][x] < cost)
			continue;

		for (int dir = 0; dir < 4; ++dir) {
			const int ny = y + dy[dir];
			const int nx = x + dx[dir];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue;

			const int ncost = cost + 1 + (MAP[ny][nx] == BUILDING ? TB : 0);

			if (dist[ny][nx] <= ncost)
				continue;

			pq.push({ ny, nx, ncost });
			dist[ny][nx] = ncost;
		}
	}

	bool safe = false;

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			if (dist[y][x] > TE) {
				safe = true;
				cout << y + 1 << ' ' << x + 1 << '\n';
			}
		}
	}

	if (!safe)
		cout << "-1\n";

	return 0;
}
