#include <iostream>
#include <vector>
using namespace std;

struct UnionFind {
	vector<int> parent;
	vector<int> cnt;

	UnionFind(int sz) : parent(sz, -1), cnt(sz, 1) {}

	int Find(int x) {
		if (parent[x] == -1) return x;
		return parent[x] = Find(parent[x]);
	}

	void Union(int a, int b) {
		int pa = Find(a);
		int pb = Find(b);
		if (pa == pb) return;
		parent[pb] = pa;
		cnt[pa] += cnt[pb];
		cnt[pb] = 0;
	}
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	vector<vector<bool>> adj(N + 1, vector<bool>(N + 1, false));

	while (true) {
		int u, v;
		cin >> u >> v;
		if (u == -1 && v == -1) break;
		adj[u][v] = adj[v][u] = true;
	}

	UnionFind uf(N + 1);

	for (int i = 1; i <= N; ++i) {
		int prev = 0;

		for (int now = 1; now <= N; ++now) {
			if (i == now)
				continue;

			if (adj[i][now])
				continue;

			if (prev)
				uf.Union(prev, now);

			prev = now;
		}
	}

	vector<int> group;

	for (int i = 1; i <= N; ++i)
		if (uf.cnt[i] > 1)
			group.push_back(i);

	if (group.size() > 2) {
		cout << "-1\n";
		return 0;
	}

	if (uf.cnt[1] == 1 && !group.empty())
		uf.Union(1, group[0]);

	vector<int> A, B;

	for (int i = 1; i <= N; ++i)
		uf.Find(i) == uf.Find(1) || uf.cnt[i] == 1 ? A.push_back(i) : B.push_back(i);

	for (int i = 0; i < A.size(); ++i) {
		for (int j = i + 1; j < A.size(); ++j) {
			if (!adj[A[i]][A[j]]) {
				cout << "-1\n";
				return 0;
			}
		}
	}

	for (int i = 0; i < B.size(); ++i) {
		for (int j = i + 1; j < B.size(); ++j) {
			if (!adj[B[i]][B[j]]) {
				cout << "-1\n";
				return 0;
			}
		}
	}

	cout << "1\n";

	for (const auto& i : A)
		cout << i << ' ';
	cout << "-1\n";

	for (const auto& i : B)
		cout << i << ' ';
	cout << "-1\n";

	return 0;
}
