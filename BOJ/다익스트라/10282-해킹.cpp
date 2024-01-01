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

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		int N, D, C;
		cin >> N >> D >> C;

		vector<vector<Edge>> adj(N + 1);

		for (int i = 0; i < D; ++i) {
			int from, to, cost;
			cin >> to >> from >> cost;
			adj[from].push_back({ to, cost });
		}

		priority_queue<Edge> pq;
		vector<int> dist(N + 1, INF);

		pq.push({ C, 0 });
		dist[C] = 0;

		while (!pq.empty()) {
			const Edge now = pq.top();
			pq.pop();

			if (dist[now.to] < now.cost)
				continue;

			for (const auto& next : adj[now.to]) {
				int ncost = dist[now.to] + next.cost;

				if (dist[next.to] <= ncost)
					continue;

				pq.push({ next.to, ncost });
				dist[next.to] = ncost;
			}
		}

		int cnt{}, sec{};

		for (const auto& d : dist) {
			if (d == INF)
				continue;

			++cnt;
			sec = max(sec, d);
		}

		cout << cnt << ' ' << sec << '\n';
	}

	return 0;
}
