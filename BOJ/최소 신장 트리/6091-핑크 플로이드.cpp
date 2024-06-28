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

	vector<Edge> edges;
	vector<vector<int>> adj(N + 1);
	UnionFind uf(N + 1);

	for (int a = 1; a <= N; ++a) {
		for (int b = a + 1; b <= N; ++b) {
			int cost;
			cin >> cost;
			edges.push_back({ a, b, cost });
		}
	}

	sort(edges.begin(), edges.end());

	for (const auto& [a, b, cost] : edges) {
		if (uf.Find(a) == uf.Find(b))
			continue;

		adj[a].push_back(b);
		adj[b].push_back(a);
		uf.Union(a, b);
	}

	for (int a = 1; a <= N; ++a) {
		cout << adj[a].size();

		sort(adj[a].begin(), adj[a].end());

		for (const auto& b : adj[a])
			cout << ' ' << b;

		cout << '\n';
	}

	return 0;
}
