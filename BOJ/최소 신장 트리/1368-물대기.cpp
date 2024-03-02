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

	int N;
	cin >> N;

	++N;

	vector<Edge> edges;

	for (int i = 0; i < N - 1; ++i) {
		int cost;
		cin >> cost;
		edges.push_back({ i, N - 1, cost });
	}

	for (int i = 0; i < N - 1; ++i) {
		for (int j = 0; j < N - 1; ++j) {
			int cost;
			cin >> cost;

			if (i < j)
				edges.push_back({ i, j, cost });
		}
	}

	sort(edges.begin(), edges.end());

	int ans = 0;
	UnionFind uf(N);

	for (const auto& [a, b, cost] : edges) {
		if (uf.Find(a) == uf.Find(b))
			continue;

		ans += cost;
		uf.Union(a, b);
	}

	cout << ans << '\n';

	return 0;
}
