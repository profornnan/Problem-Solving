#include <iostream>
#include <vector>
using namespace std;

struct UnionFind {
	vector<int> parent;
	vector<int> cycle;

	UnionFind(int sz) : parent(sz, -1), cycle(sz) {}

	int Find(int x) {
		if (parent[x] == -1) return x;
		return parent[x] = Find(parent[x]);
	}

	void Union(int a, int b) {
		int pa = Find(a);
		int pb = Find(b);

		if (pa == pb) {
			++cycle[pa];
			return;
		}

		parent[pb] = pa;
		cycle[pa] += cycle[pb];
		cycle[pb] = 0;
	}
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;

		UnionFind uf(N * 2);

		for (int i = 0; i < N; ++i) {
			int u, v;
			cin >> u >> v;
			uf.Union(u - 1, v - 1);
		}

		bool possible = true;

		for (const auto& c : uf.cycle) {
			if (c > 1) {
				possible = false;
				break;
			}
		}

		cout << (possible ? "possible" : "impossible") << '\n';
	}

	return 0;
}
