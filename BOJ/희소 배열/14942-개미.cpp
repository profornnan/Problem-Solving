#include <iostream>
#include <vector>
#include <queue>
using namespace std;

constexpr int MAX_N = 100'000;
constexpr int MAX_H = 17;

int N;
int energy[MAX_N + 1];
vector<pair<int, int>> adj[MAX_N + 1];
int parent[MAX_H][MAX_N + 1];
int length[MAX_H][MAX_N + 1];

void bfs() {
	queue<int> q;
	q.push(1);
	parent[0][1] = 1;

	while (!q.empty()) {
		const int now = q.front();
		q.pop();

		for (const auto& [next, cost] : adj[now]) {
			if (parent[0][next])
				continue;

			q.push(next);
			parent[0][next] = now;
			length[0][next] = cost;
		}
	}
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; ++i)
		cin >> energy[i];

	for (int i = 0; i < N - 1; ++i) {
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back({ v, c });
		adj[v].push_back({ u, c });
	}

	bfs();

	for (int h = 1; h < MAX_H; ++h) {
		for (int i = 1; i <= N; ++i) {
			parent[h][i] = parent[h - 1][parent[h - 1][i]];
			length[h][i] = length[h - 1][i] + length[h - 1][parent[h - 1][i]];
		}
	}

	for (int st = 1; st <= N; ++st) {
		int e = energy[st];
		int now = st;

		for (int h = MAX_H - 1; h >= 0; --h) {
			if (length[h][now] > e)
				continue;

			e -= length[h][now];
			now = parent[h][now];
		}

		cout << now << '\n';
	}

	return 0;
}
