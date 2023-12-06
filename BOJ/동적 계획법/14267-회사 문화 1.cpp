#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> adj;
vector<int> praise;

void dfs(int now) {
	for (const auto& next : adj[now]) {
		praise[next] += praise[now];
		dfs(next);
	}
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> M;

	adj.assign(N + 1, {});
	praise.assign(N + 1, 0);

	for (int c = 1; c <= N; ++c) {
		int p;
		cin >> p;
		if (p == -1) continue;
		adj[p].emplace_back(c);
	}

	for (int m = 0; m < M; ++m) {
		int i, w;
		cin >> i >> w;
		praise[i] += w;
	}

	dfs(1);

	for (int i = 1; i <= N; ++i)
		cout << praise[i] << ' ';
	cout << '\n';

	return 0;
}
