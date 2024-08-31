#include <iostream>
#include <vector>
#include <queue>
using namespace std;

constexpr int INF = 987'654'321;
constexpr int MAX_N = 1'000;

struct Edge {
	int to;
	int cost;

	bool operator<(const Edge& rhs) const {
		return cost > rhs.cost;
	}
};

int N, M;
vector<Edge> adj[MAX_N + 1];
int dist[MAX_N + 1];
int parent[MAX_N + 1];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < M; ++i) {
		int u, v, c;
		cin >> u >> v >> c;

		adj[u].push_back({ v, c });
		adj[v].push_back({ u, c });
	}

	priority_queue<Edge> pq;

	for (int i = 1; i <= N; ++i)
		dist[i] = INF;

	pq.push({ 1, 0 });
	dist[1] = 0;

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
			parent[next.to] = now.to;
		}
	}

	cout << N - 1 << '\n';

	for (int i = 2; i <= N; ++i)
		cout << i << ' ' << parent[i] << '\n';

	return 0;
}
