#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

struct Edge {
	int a;
	int b;
	double cost;

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
	cout << fixed;
	cout.precision(2);

	int N;
	cin >> N;

	vector<pair<double, double>> stars(N);
	vector<Edge> edges;
	UnionFind uf(N);

	for (auto& [x, y] : stars)
		cin >> x >> y;

	for (int a = 0; a < N; ++a) {
		for (int b = a + 1; b < N; ++b) {
			const auto& [xa, ya] = stars[a];
			const auto& [xb, yb] = stars[b];

			double cost = sqrt((xb - xa) * (xb - xa) + (yb - ya) * (yb - ya));
			edges.push_back({ a, b, cost });
		}
	}

	sort(edges.begin(), edges.end());

	double ans{};

	for (const auto& [a, b, cost] : edges) {
		if (uf.Find(a) == uf.Find(b))
			continue;

		ans += cost;
		uf.Union(a, b);
	}

	cout << ans << '\n';

	return 0;
}
