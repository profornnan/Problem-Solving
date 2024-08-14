#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

constexpr int N = 9;

const vector<vector<pair<int, int>>> jump = {
	{},
	{{2, 3}, {4, 7}, {5, 9}},
	{{5, 8}},
	{{2, 1}, {5, 7}, {6, 9}},
	{{5, 6}},
	{},
	{{5, 4}},
	{{4, 1}, {5, 3}, {8, 9}},
	{{5, 2}},
	{{5, 1}, {6, 3}, {8, 7}}
};

int T, M, E, NSTATE, ESTATE;
int adj[N + 1][N + 1];
int path[N];
bool possible;

void dfs(const int level, const int now, const int nstate, const int estate) {
	if (possible)
		return;

	if (nstate == NSTATE && estate == ESTATE) {
		possible = true;

		for (int i = 0; i < level; ++i)
			cout << path[i] << ' ';
		cout << '\n';

		return;
	}

	for (int next = 1; next <= N; ++next) {
		if (!adj[now][next])
			continue;

		if (nstate & (1 << next))
			continue;

		path[level] = next;
		dfs(level + 1, next, nstate | (1 << next), estate | (1 << adj[now][next]));
		path[level] = 0;
	}

	for (const auto& [mid, next] : jump[now]) {
		if (!adj[now][mid] || !adj[mid][next])
			continue;

		if (!(nstate & (1 << mid)))
			continue;

		if (nstate & (1 << next))
			continue;

		path[level] = next;
		dfs(level + 1, next, nstate | (1 << next), estate | (1 << adj[now][mid]) | (1 << adj[mid][next]));
		path[level] = 0;
	}
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> T;

	while (T--) {
		cin >> M;

		E = 0;
		NSTATE = 0;
		ESTATE = 0;
		memset(adj, 0, sizeof(adj));
		possible = false;

		while (M--) {
			int u, v;
			cin >> u >> v;

			for (const auto& [mid, en] : jump[u]) {
				if (v == en) {
					if (!adj[u][mid]) {
						adj[u][mid] = adj[mid][u] = ++E;

						NSTATE |= (1 << u);
						NSTATE |= (1 << mid);
						ESTATE |= (1 << E);
					}

					u = mid;

					break;
				}
			}

			if (!adj[u][v]) {
				adj[u][v] = adj[v][u] = ++E;

				NSTATE |= (1 << u);
				NSTATE |= (1 << v);
				ESTATE |= (1 << E);
			}
		}

		for (int st = 1; st <= N; ++st) {
			if (possible)
				break;

			path[0] = st;
			dfs(1, st, 1 << st, 0);
			path[0] = 0;
		}

		if (!possible)
			cout << "IMPOSSIBLE\n";
	}

	return 0;
}
