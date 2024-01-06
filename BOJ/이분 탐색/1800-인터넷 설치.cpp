#include <iostream>
#include <vector>
#include <queue>
using namespace std;

constexpr int INF = 987654321;
constexpr int MAX_N = 1'000;
constexpr int MAX_C = 1'000'000;

struct Edge {
	int to;
	int cost;

	bool operator<(const Edge& rhs) const {
		return cost > rhs.cost;
	}
};

int N, P, K;
vector<Edge> adj[MAX_N + 1];

bool dijkstra(int limit) {
	priority_queue<Edge> pq;
	vector<int> dist(N + 1, INF);

	pq.push({ 1, 0 });
	dist[1] = 0;

	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();

		if (dist[now.to] < now.cost)
			continue;

		for (const auto& next : adj[now.to]) {
			int ncost = dist[now.to] + (next.cost <= limit ? 0 : 1);

			if (dist[next.to] <= ncost)
				continue;

			pq.push({ next.to, ncost });
			dist[next.to] = ncost;
		}
	}

	return dist[N] <= K;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> P >> K;

	for (int i = 0; i < P; ++i) {
		int u, v, c;
		cin >> u >> v >> c;

		adj[u].push_back({ v, c });
		adj[v].push_back({ u, c });
	}

	int ans = -1;
	int left = 0;
	int right = MAX_C;

	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (dijkstra(mid)) {
			ans = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	cout << ans << '\n';

	return 0;
}
