#include <iostream>
using namespace std;

constexpr int MAX_N = 900;
constexpr int MAX_K = 62;

int K, N, F;
bool adj[MAX_N + 1][MAX_N + 1];
int outdegree[MAX_N + 1];
int path[MAX_K];
bool possible;

bool isValid(const int level, const int now) {
	for (int i = 0; i < level; ++i)
		if (!adj[now][path[i]])
			return false;
	return true;
}

void dfs(const int level, const int prev) {
	if (possible)
		return;

	if (level >= K) {
		possible = true;

		for (int i = 0; i < K; ++i)
			cout << path[i] << '\n';

		return;
	}

	for (int now = prev + 1; now <= N; ++now) {
		if (outdegree[now] < K - 1)
			continue;

		if (!isValid(level, now))
			continue;

		path[level] = now;
		dfs(level + 1, now);
	}
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> K >> N >> F;

	for (int i = 0; i < F; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u][v] = adj[v][u] = true;
		++outdegree[u];
		++outdegree[v];
	}

	dfs(0, 0);

	if (!possible)
		cout << "-1\n";

	return 0;
}
