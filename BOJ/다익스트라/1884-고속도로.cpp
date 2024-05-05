#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

constexpr int INF = 987654321;

struct Edge {
	int to;
	int fee;
	int cost;

	bool operator<(const Edge& rhs) const {
		return cost != rhs.cost ? cost > rhs.cost : fee > rhs.fee;
	}
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int K, N, R;
	cin >> K >> N >> R;

	vector<vector<Edge>> adj(N + 1);

	for (int i = 0; i < R; ++i) {
		int from, to, cost, fee;
		cin >> from >> to >> cost >> fee;
		adj[from].push_back({ to, fee, cost });
	}

	vector<vector<int>> dist(N + 1, vector<int>(K + 1, INF));
	priority_queue<Edge> pq;

	dist[1][0] = 0;
	pq.push({ 1, 0, 0 });

	while (!pq.empty()) {
		const Edge now = pq.top();
		pq.pop();

		if (dist[now.to][now.fee] < now.cost)
			continue;

		for (const Edge& next : adj[now.to]) {
			const int nfee = now.fee + next.fee;
			const int ncost = now.cost + next.cost;

			if (nfee > K)
				continue;

			if (dist[next.to][nfee] <= ncost)
				continue;

			for (int f = nfee; f <= K; ++f) {
				if (dist[next.to][f] <= ncost)
					break;

				dist[next.to][f] = ncost;
			}

			pq.push({ next.to, nfee, ncost });
		}
	}

	int ans = *min_element(dist[N].begin(), dist[N].end());

	cout << (ans == INF ? -1 : ans) << '\n';

	return 0;
}
