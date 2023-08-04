#include <iostream>
#include <vector>
#include <queue>
using namespace std;

constexpr int INF = 21e8;

struct Edge {
	int to;
	int cost;
	bool operator<(const Edge& next) const {
		return cost > next.cost;
	}
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<vector<Edge>> adj(N + 1);

	for (int i = 1; i <= M; ++i) {
		int from, to, cost;
		cin >> from >> to >> cost;
		adj[from].push_back({ to, cost });
	}

	int S, E;
	cin >> S >> E;

	priority_queue<Edge> pq;
	vector<int> dist(N + 1, INF);

	pq.push({ S, 0 });
	dist[S] = 0;

	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();

		if (dist[now.to] < now.cost)
			continue;

		for (const Edge& next : adj[now.to]) {
			int ncost = dist[now.to] + next.cost;

			if (dist[next.to] <= ncost)
				continue;

			pq.push({ next.to, ncost });
			dist[next.to] = ncost;
		}
	}

	cout << dist[E] << '\n';

	return 0;
}
