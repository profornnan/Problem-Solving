#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

constexpr int LIMIT = 1000;

struct Pos {
	int y;
	int x;
};

struct Node {
	int to;
	int dist;
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		int N;
		cin >> N;

		vector<Pos> pos(N + 2);
		vector<vector<Node>> adj(N + 2);

		for (auto& [y, x] : pos)
			cin >> y >> x;

		for (int u = 0; u < N + 2; ++u) {
			for (int v = u + 1; v < N + 2; ++v) {
				const int dist = abs(pos[v].y - pos[u].y) + abs(pos[v].x - pos[u].x);

				adj[u].push_back({ v, dist });
				adj[v].push_back({ u, dist });
			}
		}

		queue<int> q;
		vector<bool> visited(N + 2);

		q.push(0);
		visited[0] = true;

		while (!q.empty()) {
			int now = q.front();
			q.pop();

			for (const auto& [next, dist] : adj[now]) {
				if (visited[next])
					continue;

				if (dist > LIMIT)
					continue;

				q.push(next);
				visited[next] = true;
			}
		}

		cout << (visited[N + 1] ? "happy" : "sad") << '\n';
	}

	return 0;
}
