#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

constexpr int INF = 987654321;
constexpr int MAX_N = 4'000;

struct Edge {
	int to;
	int cost;
	bool exhausted;

	bool operator<(const Edge& rhs) const {
		return cost > rhs.cost;
	}
};

int N, M;
vector<pair<int, int>> adj[MAX_N + 1];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < M; ++i) {
		int u, v, c;
		cin >> u >> v >> c;

		adj[u].push_back({ v, c * 2 });
		adj[v].push_back({ u, c * 2 });
	}

	priority_queue<Edge> pq;
	vector<int> foxDist(N + 1, INF);

	pq.push({ 1, 0 });
	foxDist[1] = 0;

	while (!pq.empty()) {
		const auto [now, cost, exhausted] = pq.top();
		pq.pop();

		if (foxDist[now] < cost)
			continue;

		for (const auto& [next, weight] : adj[now]) {
			int ncost = cost + weight;

			if (foxDist[next] <= ncost)
				continue;

			pq.push({ next, ncost });
			foxDist[next] = ncost;
		}
	}

	vector<vector<int>> wolfDist(N + 1, vector<int>(2, INF));

	pq.push({ 1, 0, false });
	wolfDist[1][0] = 0;

	while (!pq.empty()) {
		const auto [now, cost, exhausted] = pq.top();
		pq.pop();

		if (wolfDist[now][exhausted] < cost)
			continue;

		for (const auto& [next, weight] : adj[now]) {
			int ncost = cost + (exhausted ? weight * 2 : weight / 2);

			if (wolfDist[next][!exhausted] <= ncost)
				continue;

			pq.push({ next, ncost, !exhausted });
			wolfDist[next][!exhausted] = ncost;
		}
	}

	int ans = 0;

	for (int i = 1; i <= N; ++i)
		if (foxDist[i] < min(wolfDist[i][0], wolfDist[i][1]))
			++ans;

	cout << ans << '\n';

	return 0;
}
