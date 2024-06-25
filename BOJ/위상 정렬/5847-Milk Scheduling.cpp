#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> adj(N + 1);
	vector<int> indegree(N + 1);
	vector<int> cost(N + 1);
	vector<int> dist(N + 1);
	queue<int> q;

	for (int i = 1; i <= N; ++i)
		cin >> cost[i];

	for (int i = 1; i <= M; ++i) {
		int from, to;
		cin >> from >> to;
		adj[from].push_back(to);
		++indegree[to];
	}

	for (int i = 1; i <= N; ++i) {
		if (indegree[i] == 0) {
			q.push(i);
			dist[i] = cost[i];
		}
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (const auto& next : adj[now]) {
			if (indegree[next] == 0)
				continue;

			dist[next] = max(dist[next], dist[now]);

			if (--indegree[next] == 0) {
				q.push(next);
				dist[next] += cost[next];
			}
		}
	}

	cout << *max_element(dist.begin(), dist.end()) << '\n';

	return 0;
}
