#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

constexpr int INF = 987654321;
constexpr int dx[]{ 0, -1, 0, 1 };
constexpr int dy[]{ -1, 0, 1, 0 };

struct Edge {
	int y;
	int x;
	int cost;

	bool operator<(const Edge& rhs) const {
		return cost > rhs.cost;
	}
};

void dijkstra(const vector<vector<int>>& height, vector<vector<int>>& dist, const int T, const bool backward = false) {
	const int N = height.size();
	const int M = height[0].size();

	priority_queue<Edge> pq;
	dist.assign(N, vector<int>(M, INF));

	pq.push({ 0, 0, 0 });
	dist[0][0] = 0;

	while (!pq.empty()) {
		const auto [y, x, cost] = pq.top();
		pq.pop();

		if (dist[y][x] < cost)
			continue;

		for (int dir = 0; dir < 4; ++dir) {
			const int ny = y + dy[dir];
			const int nx = x + dx[dir];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue;

			const int diff = (height[ny][nx] - height[y][x]) * (backward ? -1 : 1);

			if (abs(diff) > T)
				continue;

			const int ncost = cost + (diff <= 0 ? 1 : diff * diff);

			if (dist[ny][nx] <= ncost)
				continue;

			pq.push({ ny, nx, ncost });
			dist[ny][nx] = ncost;
		}
	}
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, M, T, D;
	cin >> N >> M >> T >> D;

	vector<vector<int>> height(N, vector<int>(M));

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			char ch;
			cin >> ch;
			height[y][x] = ch >= 'A' && ch <= 'Z' ? ch - 'A' : ch - 'a' + 26;
		}
	}

	vector<vector<int>> fDist;
	vector<vector<int>> bDist;

	dijkstra(height, fDist, T);
	dijkstra(height, bDist, T, true);

	int ans = 0;

	for (int y = 0; y < N; ++y)
		for (int x = 0; x < M; ++x)
			if (fDist[y][x] + bDist[y][x] <= D)
				ans = max(ans, height[y][x]);

	cout << ans << '\n';

	return 0;
}
