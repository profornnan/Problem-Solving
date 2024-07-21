#include <iostream>
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

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, M, K;
	cin >> N >> M >> K;

	vector<vector<Edge>> adj(N + 1);

	for (int i = 0; i < M; ++i) {
		int u, v, c;
		cin >> u >> v >> c;

		adj[u].push_back({ v, c });
		adj[v].push_back({ u, c });
	}

	priority_queue<Edge> pq;
	vector<int> idolDist(N + 1, INF);

	pq.push({ 1, 0 });
	idolDist[1] = 0;

	while (!pq.empty()) {
		const auto now = pq.top();
		pq.pop();

		if (idolDist[now.to] < now.cost)
			continue;

		for (const auto& next : adj[now.to]) {
			int ncost = now.cost + next.cost;

			if (idolDist[next.to] <= ncost)
				continue;

			pq.push({ next.to, ncost });
			idolDist[next.to] = ncost;
		}
	}

	vector<int> fanDist(N + 1, INF);

	for (int i = 0; i < K; ++i) {
		int u;
		cin >> u;

		pq.push({ u, 0 });
		fanDist[u] = 0;
	}

	while (!pq.empty()) {
		const auto now = pq.top();
		pq.pop();

		if (fanDist[now.to] < now.cost)
			continue;

		for (const auto& next : adj[now.to]) {
			int ncost = now.cost + next.cost;

			if (fanDist[next.to] <= ncost)
				continue;

			pq.push({ next.to, ncost });
			fanDist[next.to] = ncost;
		}
	}

	bool possible = false;

	for (int i = 2; i <= N; ++i) {
		if (idolDist[i] < fanDist[i]) {
			cout << i << ' ';
			possible = true;
		}
	}

	if (!possible)
		cout << 0;

	cout << '\n';

	return 0;
}
