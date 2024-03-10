#include <iostream>
#include <vector>
using namespace std;

struct UnionFind {
	vector<int> parent;
	vector<int> weight;

	UnionFind(int sz) : parent(sz, -1), weight(sz) {}

	int Find(int x) {
		if (parent[x] == -1) return x;

		int p = Find(parent[x]);

		if (parent[x] != p)
			weight[x] += weight[parent[x]];

		return parent[x] = p;
	}

	void Union(int a, int b, int w) {
		int pa = Find(a);
		int pb = Find(b);
		if (pa == pb) return;
		parent[pb] = pa;
		weight[pb] += weight[a] - weight[b] + w;
	}
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	while (true) {
		int N, M;
		cin >> N >> M;

		if (N == 0 && M == 0)
			break;

		UnionFind uf(N + 1);

		while (M--) {
			char cmd;
			int a, b, w;

			cin >> cmd;

			if (cmd == '!') {
				cin >> a >> b >> w;
				uf.Union(a, b, w);
			}
			else if (cmd == '?') {
				cin >> a >> b;

				if (uf.Find(a) != uf.Find(b))
					cout << "UNKNOWN\n";
				else
					cout << uf.weight[b] - uf.weight[a] << '\n';
			}
		}
	}

	return 0;
}
