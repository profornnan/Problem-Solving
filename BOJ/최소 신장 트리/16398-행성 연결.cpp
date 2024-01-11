#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Edge {
	int a, b, cost;
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

	vector<Edge> edges;
	UnionFind uf(N);

	for (int a = 0; a < N; ++a) {
		for (int b = 0; b < N; ++b) {
			int cost;
			cin >> cost;

			if (a < b)
				edges.push_back({ a, b, cost });
		}
	}

	sort(edges.begin(), edges.end());

	long long ans = 0;

	for (const auto& [a, b, cost] : edges) {
		if (uf.Find(a) == uf.Find(b))
			continue;

		ans += cost;
		uf.Union(a, b);
	}

	cout << ans << '\n';

	return 0;
}
