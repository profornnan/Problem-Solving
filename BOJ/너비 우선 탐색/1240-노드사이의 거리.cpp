#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<vector<pair<int, int>>> adj(N + 1);

	for (int i = 0; i < N - 1; ++i) {
		int u, v, cost;
		cin >> u >> v >> cost;

		adj[u].push_back({ v, cost });
		adj[v].push_back({ u, cost });
	}

	for (int m = 0; m < M; ++m) {
		int st, en;
		cin >> st >> en;

		vector<int> visited(N + 1);
		queue<int> q;

		q.push(st);
		visited[st] = 1;

		while (!q.empty()) {
			int now = q.front();
			q.pop();

			for (const auto& [next, cost] : adj[now]) {
				if (visited[next])
					continue;

				q.push(next);
				visited[next] = visited[now] + cost;
			}
		}

		cout << visited[en] - 1 << '\n';
	}

	return 0;
}
