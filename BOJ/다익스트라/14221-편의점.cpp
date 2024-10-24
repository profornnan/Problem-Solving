#include <iostream>
#include <vector>
#include <queue>
using namespace std;

constexpr int INF = 987'654'321;

struct Edge {
	int to;
	int cost;

	bool operator<(const Edge& rhs) const {
		return cost > rhs.cost;
	}
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<vector<Edge>> adj(N + 1);
	vector<int> dist(N + 1, INF);

	for (int i = 0; i < M; ++i) {
		int u, v, c;
		cin >> u >> v >> c;

		adj[u].push_back({ v, c });
		adj[v].push_back({ u, c });
	}

	priority_queue<Edge> pq;

	int E, S;
	cin >> E >> S;

	vector<int> ends(E);

	for (auto& en : ends)
		cin >> en;

	for (int i = 0; i < S; ++i) {
		int st;
		cin >> st;

		pq.push({ st, 0 });
		dist[st] = 0;
	}

	while (!pq.empty()) {
		const Edge now = pq.top();
		pq.pop();

		if (dist[now.to] < now.cost)
			continue;

		for (const auto& next : adj[now.to]) {
			const int ncost = now.cost + next.cost;

			if (dist[next.to] <= ncost)
				continue;

			pq.push({ next.to, ncost });
			dist[next.to] = ncost;
		}
	}

	int minIdx = 0;

	for (const auto& en : ends) {
		if (dist[minIdx] > dist[en])
			minIdx = en;
		else if (dist[minIdx] == dist[en])
			minIdx = minIdx < en ? minIdx : en;
	}

	cout << minIdx << '\n';

	return 0;
}
