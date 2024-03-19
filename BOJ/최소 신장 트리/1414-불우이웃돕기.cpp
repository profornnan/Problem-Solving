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

	int totalSum = 0;
	vector<Edge> edges;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			char cost;
			cin >> cost;

			if (cost == '0')
				continue;
			else if (cost >= 'a' && cost <= 'z')
				cost += -'a' + 1;
			else if (cost >= 'A' && cost <= 'Z')
				cost += -'A' + 27;

			totalSum += cost;
			edges.push_back({ i, j, cost });
		}
	}

	sort(edges.begin(), edges.end());

	int minSum = 0;
	int cnt = 0;
	UnionFind uf(N);

	for (const auto& [a, b, cost] : edges) {
		if (uf.Find(a) == uf.Find(b))
			continue;

		minSum += cost;
		++cnt;
		uf.Union(a, b);
	}

	cout << (cnt + 1 == N ? totalSum - minSum : -1) << '\n';

	return 0;
}
