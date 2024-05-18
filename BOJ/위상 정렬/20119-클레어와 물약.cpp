#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, M, L;
	cin >> N >> M;

	vector<vector<int>> recipes(N + 1);
	vector<bool> visited(N + 1);

	vector<int> results(M + 1);
	vector<int> indegree(M + 1);

	queue<int> q;

	for (int now = 1; now < M + 1; ++now) {
		int K;
		cin >> K;

		for (int i = 0; i < K; ++i) {
			int prev;
			cin >> prev;
			recipes[prev].push_back(now);
			++indegree[now];
		}

		cin >> results[now];
	}

	cin >> L;

	for (int i = 0; i < L; ++i) {
		int now;
		cin >> now;
		visited[now] = true;
		q.push(now);
	}

	while (!q.empty()) {
		const int now = q.front();
		q.pop();

		for (const auto& next : recipes[now]) {
			if (indegree[next] == 0)
				continue;

			if (--indegree[next] == 0) {
				const int res = results[next];

				if (visited[res])
					continue;

				visited[res] = true;
				q.push(res);
			}
		}
	}

	cout << accumulate(visited.begin(), visited.end(), 0) << '\n';

	for (int i = 1; i < N + 1; ++i)
		if (visited[i])
			cout << i << ' ';

	cout << '\n';

	return 0;
}
