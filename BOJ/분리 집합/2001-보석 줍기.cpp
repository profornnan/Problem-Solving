#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

constexpr int MAX_N = 100;
constexpr int MAX_K = 14;

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
		parent[pb] = pa;
	}
};

int N, M, K;
int gem[MAX_K];
int cnt[1 << MAX_K];
bool connected[1 << MAX_K][MAX_K];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> M >> K;

	vector<UnionFind> ufs(K + 1, N + 1);

	for (int state = 1; state < (1 << K); ++state)
		cnt[state] = cnt[state >> 1] + (state & 1);

	for (int i = 0; i < K; ++i)
		cin >> gem[i];

	for (int i = 0; i < M; ++i) {
		int u, v, c;
		cin >> u >> v >> c;

		for (int j = 0; j <= min(c, K); ++j)
			ufs[j].Union(u, v);
	}

	for (int i = 0; i < K; ++i)
		if (ufs[0].Find(gem[i]) == ufs[0].Find(1))
			connected[1 << i][i] = true;

	int ans = 0;

	for (int state = 1; state < (1 << K); ++state) {
		UnionFind& uf = ufs[cnt[state]];

		for (int i = 0; i < K; ++i) {
			const int u = gem[i];

			if (!connected[state][i])
				continue;

			if (uf.Find(u) != uf.Find(1))
				continue;

			ans = max(ans, cnt[state]);

			for (int j = 0; j < K; ++j) {
				const int v = gem[j];

				if (state & (1 << j))
					continue;

				if (uf.Find(u) != uf.Find(v))
					continue;

				connected[state | 1 << j][j] = true;
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
