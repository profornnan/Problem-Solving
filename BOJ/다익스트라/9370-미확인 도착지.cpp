#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

constexpr int INF = 987654321;

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

	int TC;
	cin >> TC;

	while (TC--) {
		int N, M, T;
		cin >> N >> M >> T;

		int S, G, H;
		cin >> S >> G >> H;

		int ghCost{};
		vector<vector<Edge>> adj(N + 1);

		for (int i = 0; i < M; ++i) {
			int u, v, c;
			cin >> u >> v >> c;
			adj[u].push_back({ v, c });
			adj[v].push_back({ u, c });

			if ((u == G && v == H) || (u == H && v == G))
				ghCost = c;
		}

		vector<int> candidates(T);

		for (auto& E : candidates)
			cin >> E;

		sort(candidates.begin(), candidates.end());

		vector<int> sDist;
		vector<int> gDist;
		vector<int> hDist;

		dijkstra(S, adj, sDist);
		dijkstra(G, adj, gDist);
		dijkstra(H, adj, hDist);

		for (const auto& E : candidates)
			if (sDist[E] == sDist[G] + ghCost + hDist[E] || sDist[E] == sDist[H] + ghCost + gDist[E])
				cout << E << ' ';

		cout << '\n';
	}

	return 0;
}
