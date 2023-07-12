#include <iostream>
#include <vector>
using namespace std;

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

	int N, M;
	cin >> N >> M;

	vector<vector<int>> adj(N, vector<int>(N));
	vector<int> plan(M);
	UnionFind uf(N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> adj[i][j];

	for (int i = 0; i < M; i++) {
		cin >> plan[i];
		plan[i]--;
	}

	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++)
			if (adj[i][j])
				uf.Union(i, j);

	int root = uf.Find(plan[0]);

	for (int i = 1; i < M; i++) {
		if (root != uf.Find(plan[i])) {
			cout << "NO\n";
			return 0;
		}
	}

	cout << "YES\n";

	return 0;
}
