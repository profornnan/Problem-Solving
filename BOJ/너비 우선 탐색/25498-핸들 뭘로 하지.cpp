#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	string idx2char;
	cin >> idx2char;

	vector<vector<int>> adj(N);

	for (int i = 0; i < N - 1; ++i) {
		int u, v;
		cin >> u >> v;

		--u; --v;

		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}

	queue<int> nowQ;
	vector<bool> visited(N);

	nowQ.push(0);
	visited[0] = true;

	while (!nowQ.empty()) {
		cout << idx2char[nowQ.front()];

		queue<int> nextQ;

		while (!nowQ.empty()) {
			const int now = nowQ.front();
			nowQ.pop();

			for (const auto& next : adj[now]) {
				if (visited[next])
					continue;

				visited[next] = true;

				if (nextQ.empty() || idx2char[nextQ.front()] < idx2char[next]) {
					queue<int>().swap(nextQ);
					nextQ.push(next);
				}
				else if (idx2char[nextQ.front()] == idx2char[next])
					nextQ.push(next);
			}
		}

		nowQ.swap(nextQ);
	}

	cout << '\n';

	return 0;
}
