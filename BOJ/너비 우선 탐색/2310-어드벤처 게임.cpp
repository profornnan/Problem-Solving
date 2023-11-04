#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	while (true) {
		int N;
		cin >> N;
		if (!N)	break;

		vector<vector<int>> adj(N + 1);
		vector<char> ch(N + 1);
		vector<int> cost(N + 1);
		vector<int> visited(N + 1, -1);

		for (int now = 1; now <= N; ++now) {
			cin >> ch[now] >> cost[now];

			while (true) {
				int next;
				cin >> next;
				if (!next) break;

				adj[now].emplace_back(next);
			}
		}

		queue<int> q;
		const int st = 1;
		const int en = N;

		if (ch[st] == 'E') {
			q.push(st);
			visited[st] = 0;
		}
		else if (ch[st] == 'L') {
			q.push(st);
			visited[st] = cost[st];
		}

		while (!q.empty()) {
			int now = q.front();
			q.pop();

			for (const auto& next : adj[now]) {
				if (ch[next] == 'E') {
					if (visited[next] >= visited[now])
						continue;

					q.push(next);
					visited[next] = visited[now];
				}
				else if (ch[next] == 'L') {
					int ncost = max(visited[now], cost[next]);

					if (visited[next] >= ncost)
						continue;

					q.push(next);
					visited[next] = ncost;
				}
				else if (ch[next] == 'T') {
					int ncost = visited[now] - cost[next];

					if (ncost < 0)
						continue;

					q.push(next);
					visited[next] = ncost;
				}
			}
		}

		cout << (visited[en] == -1 ? "No" : "Yes") << '\n';
	}

	return 0;
}
