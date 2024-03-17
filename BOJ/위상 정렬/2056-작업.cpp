#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	vector<vector<int>> adj(N + 1);
	vector<int> income(N + 1);
	vector<int> cost(N + 1);
	vector<int> dist(N + 1);
	queue<int> q;

	for (int u = 1; u <= N; ++u) {
		int cnt;
		cin >> cost[u] >> cnt;

		while (cnt--) {
			int v;
			cin >> v;
			adj[v].push_back(u);
			++income[u];
		}
	}

	for (int u = 1; u <= N; ++u) {
		if (income[u] == 0) {
			q.push(u);
			dist[u] = cost[u];
		}
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (const auto& next : adj[now]) {
			if (income[next] == 0)
				continue;

			dist[next] = max(dist[next], dist[now]);

			if (--income[next] == 0) {
				q.push(next);
				dist[next] += cost[next];
			}
		}
	}

	cout << *max_element(dist.begin(), dist.end()) << '\n';

	return 0;
}
