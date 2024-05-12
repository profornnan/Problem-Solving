#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Edge {
	int a;
	int b;
	int cost;

	bool operator<(const Edge& rhs) const {
		return cost < rhs.cost;
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

	int N, M, K;
	cin >> N >> M >> K;

	int ans = 0;
	vector<Edge> edges(M);
	UnionFind uf(N + 1);

	for (int i = 0; i < K; ++i) {
		int st;
		cin >> st;
		uf.Union(0, st);
	}

	for (auto& [a, b, cost] : edges)
		cin >> a >> b >> cost;

	sort(edges.begin(), edges.end());

	for (const auto& [a, b, cost] : edges) {
		if (uf.Find(a) == uf.Find(b))
			continue;

		ans += cost;
		uf.Union(a, b);
	}

	cout << ans << '\n';

	return 0;
}
