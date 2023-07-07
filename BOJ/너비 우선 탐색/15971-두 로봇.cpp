#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
	int to;
	int cost;
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, st, en;
	cin >> N >> st >> en;

	vector<vector<Edge>> adj(N + 1);
	vector<int> dist(N + 1);
	vector<int> maxCost(N + 1);

	for (int i = 0; i < N - 1; i++) {
		int u, v, cost;
		cin >> u >> v >> cost;
		adj[u].push_back({ v, cost });
		adj[v].push_back({ u, cost });
	}

	queue<int> q;
	q.push(st);
	dist[st] = 1;
	maxCost[st] = 0;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (const Edge& next : adj[now]) {
			if (dist[next.to] != 0) continue;

			q.push(next.to);
			dist[next.to] = dist[now] + next.cost;
			maxCost[next.to] = max(maxCost[now], next.cost);
		}
	}

	cout << dist[en] - maxCost[en] - 1 << '\n';

	return 0;
}
