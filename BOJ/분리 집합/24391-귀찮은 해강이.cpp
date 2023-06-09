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
	cin.tie(NULL)->sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	UnionFind uf(N + 1);

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		uf.Union(u, v);
	}

	vector<int> timeTable(N);
	int ans = 0;

	cin >> timeTable[0];

	for (int i = 1; i < N; i++) {
		cin >> timeTable[i];
		if (!uf.isConnected(timeTable[i - 1], timeTable[i]))
			ans++;
	}

	cout << ans << '\n';

	return 0;
}
