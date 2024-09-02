#include <iostream>
#include <vector>
using namespace std;

struct UnionFind {
	vector<int> parent;

	UnionFind(int sz) : parent(sz, -1) {}

	int Find(int x) {
		if (parent[x] == -1) return x;
		return parent[x] = Find(parent[x]);
	}

	void Union(int a, int b) {
		int pa = Find(a);
		int pb = Find(b);
		if (pa == pb) return;
		parent[pa] = pb;
	}
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> enemy(N + 1);
	UnionFind uf(N + 1);

	for (int i = 0; i < M; ++i) {
		char ch;
		int u, v;

		cin >> ch >> u >> v;

		if (ch == 'F') {
			uf.Union(u, v);
		}
		else if (ch == 'E') {
			enemy[u].push_back(v);
			enemy[v].push_back(u);
		}
	}

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j < enemy[i].size(); ++j)
			uf.Union(enemy[i][j - 1], enemy[i][j]);

	int ans = 0;

	for (int i = 1; i <= N; ++i)
		if (uf.parent[i] == -1)
			++ans;

	cout << ans << '\n';

	return 0;
}
