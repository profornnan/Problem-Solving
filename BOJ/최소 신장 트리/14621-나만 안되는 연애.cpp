#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Edge {
	int u;
	int v;
	int cost;
	bool operator<(const Edge& next) const {
		return cost < next.cost;
	}
};

class UnionFind {
private:
	vector<int> parent;

public:
	UnionFind(int sz) : parent(sz, -1) {};
	
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

	bool isConnected(int a, int b) {
		return Find(a) == Find(b);
	}
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<char> gender(N + 1);
	vector<Edge> edges(M);

	for (int i = 1; i <= N; i++)
		cin >> gender[i];

	for (Edge& edge : edges)
		cin >> edge.u >> edge.v >> edge.cost;

	UnionFind uf(N + 1);
	sort(edges.begin(), edges.end());
	int cnt = 0, sum = 0;

	for (const Edge& edge : edges) {
		if (uf.isConnected(edge.u, edge.v)) continue;
		if (gender[edge.u] == gender[edge.v]) continue;

		cnt++;
		sum += edge.cost;
		uf.Union(edge.u, edge.v);
	}

	cout << (cnt == N - 1 ? sum : -1) << '\n';

	return 0;
}
