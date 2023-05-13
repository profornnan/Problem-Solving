#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
	int to;
	int cost;

	bool operator<(const Edge& next) const {
		return cost > next.cost;
	}
};

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	int N, M, K;
	cin >> N >> M >> K;

	vector<vector<Edge>> adj(N + 1);

	for (int i = 0; i < M; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		adj[from].push_back({ to, cost });
	}

	vector<priority_queue<int>> dist(N + 1);
	priority_queue<Edge> pq;

	dist[1].push(0);
	pq.push({ 1, 0 });

	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();

		for (const Edge& next : adj[now.to]) {
			int ncost = now.cost + next.cost;

			if (dist[next.to].size() < K) {
				dist[next.to].push(ncost);
				pq.push({ next.to, ncost });
			}
			else if (dist[next.to].top() > ncost) {
				dist[next.to].pop();
				dist[next.to].push(ncost);
				pq.push({ next.to, ncost });
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		if (dist[i].size() != K) cout << "-1\n";
		else cout << dist[i].top() << '\n';
	}

	return 0;
}
