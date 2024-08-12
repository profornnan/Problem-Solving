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

	int N, C;
	cin >> N >> C;

	vector<pair<int, int>> fields(N);
	vector<Edge> edges;

	for (int i = 0; i < N; ++i) {
		auto& [yi, xi] = fields[i];
		cin >> yi >> xi;

		for (int j = 0; j < i; ++j) {
			const auto& [yj, xj] = fields[j];
			const int cost = (yi - yj) * (yi - yj) + (xi - xj) * (xi - xj);

			if (cost >= C)
				edges.push_back({ i, j, cost });
		}
	}

	sort(edges.begin(), edges.end());

	int ans = 0;
	int cnt = 0;
	UnionFind uf(N);

	for (const auto& [a, b, cost] : edges) {
		if (uf.Find(a) == uf.Find(b))
			continue;

		ans += cost;
		++cnt;
		uf.Union(a, b);

		if (cnt == N - 1) {
			cout << ans << '\n';
			return 0;
		}
	}

	cout << "-1\n";

	return 0;
}
