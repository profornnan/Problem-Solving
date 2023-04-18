#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

int N, M, H;
vector<vector<int>> adj;
vector<int> parent;
vector<vector<int>> sparseTable;
vector<int> level;
int maxLevel;

void bfs() {
	queue<int> q;
	q.push(1);
	parent[1] = 1;
	level[1] = 0;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int next : adj[now]) {
			if (level[next] != -1) continue;

			q.push(next);
			parent[next] = now;
			level[next] = level[now] + 1;

			maxLevel = max(maxLevel, level[next]);
		}
	}
}

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
	cin >> N;

	adj = vector<vector<int>>(N + 1);
	parent = vector<int>(N + 1);
	level = vector<int>(N + 1, -1);

	for (int i = 0; i < N - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	bfs();

	H = ceil(log2(maxLevel));

	sparseTable = vector<vector<int>>(H, vector<int>(N + 1));

	sparseTable[0].swap(parent);

	for (int h = 1; h < H; h++)
		for (int i = 1; i < N + 1; i++)
			sparseTable[h][i] = sparseTable[h - 1][sparseTable[h - 1][i]];

	cin >> M;

	while (M--) {
		int u, v;
		cin >> u >> v;

		if (level[u] < level[v])
			swap(u, v);

		int diff = level[u] - level[v];

		if (diff > 0)
			for (int i = H - 1; i >= 0; i--)
				if (diff & (1 << i))
					u = sparseTable[i][u];

		if (u != v) {
			for (int i = H - 1; i >= 0; i--) {
				if (sparseTable[i][u] != sparseTable[i][v]) {
					u = sparseTable[i][u];
					v = sparseTable[i][v];
				}
			}
			u = v = sparseTable[0][u];
		}

		cout << u << '\n';
	}

	return 0;
}
