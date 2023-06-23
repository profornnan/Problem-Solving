#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

constexpr int INF = 987654321;

struct Bridge {
	int u;
	int v;
	int limit;
	bool operator<(const Bridge& next) const {
		return limit > next.limit;
	}
};

struct Edge {
	int to;
	int limit;
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

	bool isConnected(int a, int b) {
		return Find(a) == Find(b);
	}
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, M, st, en;
	cin >> N >> M >> st >> en;

	vector<Bridge> bridges(M);
	vector<vector<Edge>> adj(N + 1);
	vector<int> visited(N + 1);

	for (Bridge& bridge : bridges)
		cin >> bridge.u >> bridge.v >> bridge.limit;

	sort(bridges.begin(), bridges.end());

	UnionFind uf(N + 1);

	for (const Bridge& bridge : bridges) {
		if (uf.isConnected(bridge.u, bridge.v)) continue;

		adj[bridge.u].push_back({ bridge.v, bridge.limit });
		adj[bridge.v].push_back({ bridge.u, bridge.limit });

		uf.Union(bridge.u, bridge.v);
	}

	queue<Edge> q;
	q.push({ st, INF });
	visited[st] = INF;

	while (!q.empty()) {
		Edge now = q.front();
		q.pop();

		for (const Edge& next : adj[now.to]) {
			if (visited[next.to]) continue;

			visited[next.to] = min(visited[now.to], next.limit);
			q.push({ next.to, visited[next.to] });
		}
	}

	cout << visited[en] << '\n';

	return 0;
}
