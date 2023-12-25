#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

constexpr int MAX_N = 40'000;
constexpr int MAX_H = 16;

int N, M;
vector<pair<int, int>> adj[MAX_N + 1];
int parent[MAX_H][MAX_N + 1];
int length[MAX_H][MAX_N + 1];
int level[MAX_N + 1];

void bfs() {
	queue<int> q;
	q.push(1);
	parent[0][1] = 1;
	level[1] = 0;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (const auto& [next, cost] : adj[now]) {
			if (level[next] != -1)
				continue;

			q.push(next);
			parent[0][next] = now;
			length[0][next] = cost;
			level[next] = level[now] + 1;
		}
	}
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N - 1; ++i) {
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back({ v, c });
		adj[v].push_back({ u, c });
	}

	memset(level, -1, sizeof(level));

	bfs();

	for (int h = 1; h < MAX_H; ++h) {
		for (int i = 1; i <= N; ++i) {
			parent[h][i] = parent[h - 1][parent[h - 1][i]];
			length[h][i] = length[h - 1][i] + length[h - 1][parent[h - 1][i]];
		}
	}

	cin >> M;

	while (M--) {
		int u, v;
		cin >> u >> v;

		if (level[u] < level[v])
			swap(u, v);

		int diff = level[u] - level[v];
		int lenSum = 0;

		if (diff > 0) {
			for (int h = MAX_H - 1; h >= 0; --h) {
				if (diff & (1 << h)) {
					lenSum += length[h][u];
					u = parent[h][u];
				}
			}
		}

		if (u != v) {
			for (int h = MAX_H - 1; h >= 0; --h) {
				if (parent[h][u] != parent[h][v]) {
					lenSum += length[h][u] + length[h][v];
					u = parent[h][u];
					v = parent[h][v];
				}
			}
			lenSum += length[0][u] + length[0][v];
			u = v = parent[0][u];
		}

		cout << lenSum << '\n';
	}

	return 0;
}
