#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	vector<vector<int>> adj(N + 1);

	for (int u = 1; u <= N; ++u) {
		while (true) {
			int v;
			cin >> v;

			if (!v) break;
			adj[u].push_back(v);
		}
	}

	queue<int> q;
	vector<int> visited(N + 1);
	vector<int> cnt(N + 1);

	int M;
	cin >> M;

	for (int i = 0; i < M; ++i) {
		int st;
		cin >> st;

		q.push(st);
		visited[st] = 1;
	}

	while (!q.empty()) {
		const int now = q.front();
		q.pop();

		for (const auto& next : adj[now]) {
			if (visited[next])
				continue;

			if (++cnt[next] < (adj[next].size() + 1) / 2)
				continue;

			q.push(next);
			visited[next] = visited[now] + 1;
		}
	}

	for (int i = 1; i <= N; ++i)
		cout << visited[i] - 1 << ' ';
	cout << '\n';

	return 0;
}
