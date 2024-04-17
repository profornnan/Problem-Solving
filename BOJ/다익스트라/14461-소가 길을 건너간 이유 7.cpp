#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

constexpr int INF = 987654321;
constexpr int MAX_N = 100;
constexpr int dx[]{ 3, 0, -3, 0, 2, 2, 1, -1, -2, -2, -1, 1, 1, 0, -1, 0 };
constexpr int dy[]{ 0, -3, 0, 3, 1, -1, -2, -2, -1, 1, 2, 2, 0, -1, 0, 1 };

struct Edge {
	int y;
	int x;
	int cost;

	bool operator<(const Edge& rhs) const {
		return cost > rhs.cost;
	}
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, T;
	cin >> N >> T;

	vector<vector<int>> MAP(N, vector<int>(N));
	vector<vector<int>> dist(N, vector<int>(N, INF));

	for (int y = 0; y < N; ++y)
		for (int x = 0; x < N; ++x)
			cin >> MAP[y][x];

	int ans = INF;
	priority_queue<Edge> pq;

	pq.push({ 0, 0, 0 });
	dist[0][0] = 0;

	while (!pq.empty()) {
		const auto [y, x, cost] = pq.top();
		pq.pop();

		if (dist[y][x] < cost)
			continue;

		int diff = 2 * (N - 1) - y - x;

		if (diff <= 2)
			ans = min(ans, cost + T * diff);

		for (int dir = 0; dir < 16; ++dir) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N)
				continue;

			int ncost = cost + T * 3 + MAP[ny][nx];

			if (dist[ny][nx] <= ncost)
				continue;

			pq.push({ ny, nx, ncost });
			dist[ny][nx] = ncost;
		}
	}

	cout << ans << '\n';

	return 0;
}
