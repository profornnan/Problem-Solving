#include <iostream>
#include <queue>
using namespace std;

constexpr long long INF = 2e18;
constexpr int MAX_N = 400;
constexpr int dx[]{ 1, 0, -1, 0 };
constexpr int dy[]{ 0, -1, 0, 1 };

struct Edge {
	int y;
	int x;
	long long cost;

	bool operator<(const Edge& rhs) const {
		return cost > rhs.cost;
	}
};

int N;
int MAP[MAX_N][MAX_N];
long long dist[MAX_N][MAX_N];
int sy, sx, ey, ex;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;
	cin >> sx >> sy >> ex >> ey;
	--sx; --sy; --ex; --ey;

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			cin >> MAP[y][x];
			dist[y][x] = INF;
		}
	}

	if (MAP[sy][sx] == -1 || MAP[ey][ex] == -1) {
		cout << "-1\n";
		return 0;
	}

	priority_queue<Edge> pq;

	pq.push({ sy, sx, MAP[sy][sx] });
	dist[sy][sx] = MAP[sy][sx];

	while (!pq.empty()) {
		const auto [y, x, cost] = pq.top();
		pq.pop();

		if (y == ey && x == ex) {
			cout << dist[y][x] << '\n';
			return 0;
		}

		if (dist[y][x] < cost)
			continue;

		for (int dir = 0; dir < 4; ++dir) {
			const int ny = y + dy[dir];
			const int nx = x + dx[dir];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N)
				continue;

			if (MAP[ny][nx] == -1)
				continue;

			const long long ncost = cost + MAP[ny][nx];

			if (dist[ny][nx] <= ncost)
				continue;

			pq.push({ ny, nx, ncost });
			dist[ny][nx] = ncost;
		}
	}

	cout << "-1\n";

	return 0;
}
