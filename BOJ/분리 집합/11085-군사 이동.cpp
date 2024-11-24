#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Edge {
	int a;
	int b;
	int width;

	bool operator<(const Edge& rhs) const {
		return width > rhs.width;
	}
};

class UnionFind {
private:
	vector<int> parent;

public:
	UnionFind(int sz) : parent(sz, -1) {}

	int Find(int x) {
		if (parent[x] == -1) return x;
		return parent[x] = Find(parent[x]);
	}

	void Union(int a, int b) {
		int pa = Find(a);
		int pb = Find(b);
		if (pa == pb) return;
		parent[pb] = pa;
	}
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, M, st, en;
	cin >> N >> M >> st >> en;

	UnionFind uf(N);
	vector<Edge> edges(M);

	for (auto& [a, b, width] : edges)
		cin >> a >> b >> width;

	sort(edges.begin(), edges.end());

	for (const auto& [a, b, width] : edges) {
		uf.Union(a, b);

		if (uf.Find(st) == uf.Find(en)) {
			cout << width << '\n';
			return 0;
		}
	}

	return 0;
}
