#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Edge {
	int a, b, cost;
	bool operator<(const Edge& next) const {
		return cost < next.cost;
	}
};

class UnionFind {
private:
	vector<int> parent;

public:
	UnionFind(int sz) : parent(vector<int>(sz, -1)) {}

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

	while (true) {
		int N, M;
		cin >> N >> M;

		if (N == 0 && M == 0)
			break;

		vector<Edge> edges(M);
		UnionFind uf(N);

		int totalSum = 0;
		int minSum = 0;

		for (Edge& edge : edges) {
			cin >> edge.a >> edge.b >> edge.cost;
			totalSum += edge.cost;
		}

		sort(edges.begin(), edges.end());

		for (const Edge& edge : edges) {
			if (uf.Find(edge.a) == uf.Find(edge.b))
				continue;

			minSum += edge.cost;
			uf.Union(edge.a, edge.b);
		}

		cout << totalSum - minSum << '\n';
	}

	return 0;
}
