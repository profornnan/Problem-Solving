#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using pii = pair<int, int>;

constexpr int INF = 21e8;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<vector<pii>> adj(N + 1);
	vector<int> dist(N + 1, INF);
	vector<int> parent(N + 1);
	vector<int> cycleNode;

	for (int i = 0; i < M; ++i) {
		int from, to, cost;
		cin >> from >> to >> cost;
		adj[from].push_back({ to, -cost });
	}

	dist[1] = 0;

	for (int i = 1; i <= N; ++i) {
		for (int now = 1; now <= N; ++now) {
			for (const auto& [next, cost] : adj[now]) {
				if (dist[now] != INF && dist[next] > dist[now] + cost) {
					dist[next] = dist[now] + cost;
					parent[next] = now;
					if (i == N) cycleNode.emplace_back(now);
				}
			}
		}
	}

	vector<bool> visited(N + 1);
	queue<int> q;

	for (const int& node : cycleNode) {
		visited[node] = true;
		q.push(node);
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (const auto& [next, ignore] : adj[now]) {
			if (visited[next]) continue;
			visited[next] = true;
			q.push(next);
		}
	}

	if (dist[N] == INF || visited[N]) {
		cout << "-1\n";
		return 0;
	}

	vector<int> path;
	int now = N;

	while (now) {
		path.emplace_back(now);
		now = parent[now];
	}

	for (auto it = path.rbegin(); it != path.rend(); ++it)
		cout << *it << ' ';

	return 0;
}
