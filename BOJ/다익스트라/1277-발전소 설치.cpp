#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

constexpr double INF = 987654321L;

struct Pos {
	int y;
	int x;
};

struct Edge {
	int to;
	double cost;

	bool operator<(const Edge& rhs) const {
		return cost > rhs.cost;
	}
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cout << fixed;
	cout.precision(0);

	int N, W;
	cin >> N >> W;

	double M;
	cin >> M;

	vector<Pos> plants(N);

	for (auto& [y, x] : plants)
		cin >> y >> x;

	vector<vector<Edge>> adj(N);

	for (int u = 0; u < N; ++u) {
		for (int v = 0; v < N; ++v) {
			if (u == v)
				continue;

			const auto& [y1, x1] = plants[u];
			const auto& [y2, x2] = plants[v];

			double cost = sqrt(pow(abs(y2 - y1), 2) + pow(abs(x2 - x1), 2));

			if (cost > M)
				continue;

			adj[u].push_back({ v, cost });
			adj[v].push_back({ u, cost });
		}
	}

	for (int i = 0; i < W; ++i) {
		int u, v;
		cin >> u >> v;

		--u; --v;

		adj[u].push_back({ v, 0 });
		adj[v].push_back({ u, 0 });
	}

	priority_queue<Edge> pq;
	vector<double> dist(N, INF);

	pq.push({ 0, 0 });
	dist[0] = 0;

	while (!pq.empty()) {
		const Edge now = pq.top();
		pq.pop();

		if (dist[now.to] < now.cost)
			continue;

		for (const auto& next : adj[now.to]) {
			double ncost = dist[now.to] + next.cost;

			if (dist[next.to] <= ncost)
				continue;

			pq.push({ next.to, ncost });
			dist[next.to] = ncost;
		}
	}

	cout << floor(dist[N - 1] * 1000L) << '\n';

	return 0;
}
