#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

struct UnionFind {
	vector<int> parent;

	UnionFind(int sz) : parent(sz, -1) {}

	int Find(int x) {
		if (parent[x] == -1) return x;
		return parent[x] = Find(parent[x]);
	}

	void Union(int a, int b) {
		int pa = Find(a);
		int pb = Find(b);
		if (pa == pb) return;
		parent[pa] = pb;
	}
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, M, Q;
	cin >> N >> M >> Q;

	int V = 0;
	unordered_map<int, int> um;
	vector<pair<int, int>> edges(M);

	for (auto& [u, v] : edges) {
		cin >> u >> v;

		if (!um.count(u))
			um.insert({ u, V++ });

		if (!um.count(v))
			um.insert({ v, V++ });

		u = um[u];
		v = um[v];
	}

	vector<vector<int>> adj(V);
	UnionFind uf(V);

	for (const auto& [u, v] : edges) {
		adj[u].push_back(v);
		adj[v].push_back(u);

		uf.Union(u, v);
	}

	int G = 0;

	for (const auto& p : uf.parent)
		if (p == -1)
			++G;

	vector<vector<int>> visitedArr(V, vector<int>(V));

	for (int st = 0; st < V; ++st) {
		queue<int> q;
		vector<int>& visited = visitedArr[st];

		q.push(st);
		visited[st] = 1;

		while (!q.empty()) {
			const int now = q.front();
			q.pop();

			for (const auto& next : adj[now]) {
				if (visited[next])
					continue;

				q.push(next);
				visited[next] = visited[now] + 1;
			}
		}
	}

	while (Q--) {
		int st, en;
		cin >> st >> en;

		if (st == en) {
			cout << "0\n";
			continue;
		}

		if (!um.count(st) || !um.count(en)) {
			cout << "1\n";
			continue;
		}

		st = um[st];
		en = um[en];

		if (uf.Find(st) != uf.Find(en)) {
			cout << "1\n";
			continue;
		}

		if (!(G == 1 && V == N)) {
			cout << (find(adj[st].begin(), adj[st].end(), en) != adj[st].end() ? 1 : 2) << '\n';
			continue;
		}

		cout << visitedArr[st][en] - 1 << '\n';
	}

	return 0;
}
