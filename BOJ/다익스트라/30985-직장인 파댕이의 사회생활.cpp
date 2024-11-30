#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

constexpr long long INF = 2e18;

struct Edge {
	int to;
	long long cost;

	bool operator<(const Edge& rhs) const {
		return cost > rhs.cost;
	}
};

void dijkstra(const int st, const vector<vector<Edge>>& adj, vector<long long>& dist) {
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
			const long long ncost = now.cost + next.cost;

			if (dist[next.to] <= ncost)
				continue;

			pq.push({ next.to, ncost });
			dist[next.to] = ncost;
		}
	}
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, M, K;
	cin >> N >> M >> K;

	vector<vector<Edge>> adj(N + 1);
	vector<long long> elevator(N + 1);

	for (int i = 0; i < M; ++i) {
		int u, v, c;
		cin >> u >> v >> c;

		adj[u].push_back({ v, c });
		adj[v].push_back({ u, c });
	}

	for (int i = 1; i <= N; ++i)
		cin >> elevator[i];

	vector<long long> sDist;
	vector<long long> eDist;

	dijkstra(1, adj, sDist);
	dijkstra(N, adj, eDist);

	long long ans = INF;

	for (int i = 1; i <= N; ++i)
		if (elevator[i] != -1)
			ans = min(ans, sDist[i] + elevator[i] * (K - 1) + eDist[i]);

	cout << (ans == INF ? -1 : ans) << '\n';

	return 0;
}
