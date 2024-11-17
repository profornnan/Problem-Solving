#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Edge {
	int a;
	int b;
	int num;
	int cost;

	bool operator<(const Edge& rhs) const {
		return num != rhs.num ? num < rhs.num : cost < rhs.cost;
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

	int N, M;
	cin >> N >> M;

	vector<Edge> edges(M);

	for (auto& [a, b, num, cost] : edges)
		cin >> a >> b >> num >> cost;

	sort(edges.begin(), edges.end());

	UnionFind uf(N + 1);
	vector<int> minNums;
	long long minCostSum = 0;
	int cnt = 0;

	for (const auto& [a, b, num, cost] : edges) {
		if (uf.Find(a) == uf.Find(b))
			continue;

		uf.Union(a, b);
		minNums.push_back(num);
		minCostSum += cost;
		++cnt;
	}

	if (cnt != N - 1) {
		cout << "-1\n";
		return 0;
	}

	sort(minNums.begin(), minNums.end());

	for (const auto& num : minNums)
		cout << num;

	cout << ' ' << minCostSum << '\n';

	return 0;
}
