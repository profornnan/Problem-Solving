#include <iostream>
#include <vector>
#include <queue>
using namespace std;

constexpr long long INF = 2e18;

struct Edge {
	int to;
	int cost;
};

struct Node {
	int paveCnt;
	int to;
	long long dist;

	bool operator<(const Node& next) const {
		return dist > next.dist;
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

	vector<vector<long long>> minDist(K + 1, vector<long long>(N + 1, INF));
	priority_queue<Node> pq;

	minDist[0][1] = 0;
	pq.push({ 0, 1, 0 });

	while (!pq.empty()) {
		auto [paveCnt, now, dist] = pq.top();
		pq.pop();

		if (minDist[paveCnt][now] < dist)
			continue;

		for (const auto& [next, cost] : adj[now]) {
			long long ndist = minDist[paveCnt][now] + cost;

			if (minDist[paveCnt][next] > ndist) {
				minDist[paveCnt][next] = ndist;
				pq.push({ paveCnt, next, ndist });
			}

			if (paveCnt < K && minDist[paveCnt + 1][next] > dist) {
				minDist[paveCnt + 1][next] = dist;
				pq.push({ paveCnt + 1, next, dist });
			}
		}
	}

	long long ans = INF;

	for (int k = 0; k <= K; ++k)
		ans = ans < minDist[k][N] ? ans : minDist[k][N];

	cout << ans << '\n';

	return 0;
}
