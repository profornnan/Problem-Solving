#include <iostream>
#include <vector>
using namespace std;

constexpr int INF = 21e8;

struct Edge {
	int a;
	int b;
	int cost;
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

	int N, M;
	cin >> N >> M;

	vector<Edge> edges(M);

	int left = INF;
	int right = 0;

	for (auto& [a, b, cost] : edges) {
		cin >> a >> b >> cost;
		left = left < cost ? left : cost;
		right = right > cost ? right : cost;
	}

	int st, en;
	cin >> st >> en;

	int ans = 0;

	while (left <= right) {
		int mid = left + (right - left) / 2;

		UnionFind uf(N + 1);

		for (const auto [a, b, cost] : edges)
			if (cost >= mid)
				uf.Union(a, b);

		if (uf.Find(st) == uf.Find(en)) {
			ans = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	cout << ans << '\n';

	return 0;
}
