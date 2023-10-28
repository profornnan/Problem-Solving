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

	UnionFind uf(N);

	for (int i = 1; i <= M; ++i) {
		int a, b;
		cin >> a >> b;

		if (uf.isConnected(a, b)) {
			cout << i << '\n';
			return 0;
		}

		uf.Union(a, b);
	}

	cout << "0\n";

	return 0;
}
