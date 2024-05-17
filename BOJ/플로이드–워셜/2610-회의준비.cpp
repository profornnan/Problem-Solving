#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

constexpr int INF = 987654321;

struct UnionFind {
	vector<int> parent;
	vector<int> cost;

	UnionFind(int sz) : parent(sz, -1), cost(sz) {}

	int Find(int x) {
		if (parent[x] == -1) return x;
		return parent[x] = Find(parent[x]);
	}

	void Union(int a, int b) {
		int pa = Find(a);
		int pb = Find(b);
		if (pa == pb) return;
		cost[pa] < cost[pb] ? parent[pb] = pa : parent[pa] = pb;
	}
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<pair<int, int>> edges(M);
	vector<vector<int>> dist(N + 1, vector<int>(N + 1, INF));

	for (auto& [u, v] : edges) {
		cin >> u >> v;
		dist[u][v] = dist[v][u] = 1;
	}

	for (int k = 1; k <= N; ++k)
		for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= N; ++j)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	UnionFind uf(N + 1);
	vector<int> ans;

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			if (i != j && dist[i][j] != INF)
				uf.cost[i] = max(uf.cost[i], dist[i][j]);

	for (const auto& [u, v] : edges)
		uf.Union(u, v);

	for (int i = 1; i <= N; ++i)
		if (uf.parent[i] == -1)
			ans.push_back(i);

	cout << ans.size() << '\n';

	for (const auto& i : ans)
		cout << i << '\n';

	return 0;
}
