#include <iostream>
#include <vector>
using namespace std;

struct UnionFind {
	vector<int> parent;
	vector<bool> isCycle;

	UnionFind(int sz) : parent(sz, -1), isCycle(sz, false) {}

	int Find(int x) {
		if (parent[x] == -1) return x;
		return parent[x] = Find(parent[x]);
	}

	void Union(int a, int b) {
		int pa = Find(a);
		int pb = Find(b);

		if (pa == pb) {
			isCycle[pa] = true;
			return;
		}

		parent[pb] = pa;
		isCycle[pa] = isCycle[pa] || isCycle[pb];
	}
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int T = 0;

	while (true) {
		int N, M;
		cin >> N >> M;

		if (N == 0 && M == 0)
			break;

		cout << "Case " << ++T << ": ";

		int a, b;
		UnionFind uf(N + 1);

		for (int i = 0; i < M; ++i) {
			cin >> a >> b;
			uf.Union(a, b);
		}

		int cnt = 0;

		for (int i = 1; i <= N; ++i)
			if (uf.parent[i] == -1 && !uf.isCycle[i])
				++cnt;

		if (cnt == 0)
			cout << "No trees.\n";
		else if (cnt == 1)
			cout << "There is one tree.\n";
		else if (cnt > 1)
			cout << "A forest of " << cnt << " trees.\n";
	}

	return 0;
}
