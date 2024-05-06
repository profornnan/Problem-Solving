#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

constexpr int INF = 21e8;

struct Edge {
	int to;
	int cost;

	bool operator<(const Edge& rhs) const {
		return cost > rhs.cost;
	}
};

void dijkstra(const int st, const vector<vector<Edge>>& adj, vector<int>& dist) {
	priority_queue<Edge> pq;
	dist.assign(adj.size(), INF);

	pq.push({ st, 0 });
	dist[st] = 0;

	while (!pq.empty()) {
		const Edge now = pq.top();
		pq.pop();

		if (dist[now.to] < now.cost)
			continue;

		for (const auto& next : adj[now.to]) {
			int ncost = now.cost + next.cost;

			if (dist[next.to] <= ncost)
				continue;

			pq.push({ next.to, ncost });
			dist[next.to] = ncost;
		}
	}
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int M, N, S, E1, E2;
	cin >> M >> N >> S >> E1 >> E2;

	vector<vector<Edge>> adj(N + 1);

	for (int i = 0; i < M; ++i) {
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back({ v, c });
		adj[v].push_back({ u, c });
	}

	vector<int> E1Dist;
	vector<int> E2Dist;

	dijkstra(E1, adj, E1Dist);
	dijkstra(E2, adj, E2Dist);

	cout << min(E1Dist[S] + E1Dist[E2], E2Dist[S] + E2Dist[E1]) << '\n';

	return 0;
}
