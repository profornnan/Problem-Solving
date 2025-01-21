#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<int> st(M);

	for (auto& id : st)
		cin >> id;

	int K;
	cin >> K;

	vector<vector<int>> adj(N + 1);
	vector<bool> visited(N + 1);

	vector<vector<int>> result(K + 1);
	vector<int> indegree(K + 1);

	queue<int> q;

	for (int k = 1; k <= K; ++k) {
		int L, R;
		cin >> L >> R;

		while (L--) {
			int from;
			cin >> from;
			adj[from].push_back(k);
			++indegree[k];
		}

		while (R--) {
			int to;
			cin >> to;
			result[k].push_back(to);
		}
	}

	for (const auto& id : st) {
		visited[id] = true;
		q.push(id);
	}

	while (!q.empty()) {
		const int now = q.front();
		q.pop();

		for (const auto& next : adj[now]) {
			if (indegree[next] == 0)
				continue;

			if (--indegree[next] == 0) {
				for (const auto& id : result[next]) {
					if (visited[id])
						continue;

					visited[id] = true;
					q.push(id);
				}
			}
		}
	}

	cout << accumulate(visited.begin(), visited.end(), 0) << '\n';

	for (int i = 1; i <= N; ++i)
		if (visited[i])
			cout << i << ' ';

	cout << '\n';

	return 0;
}
