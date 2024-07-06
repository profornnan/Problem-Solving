#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

constexpr int MAX_V = 10'000;

int V, E, dcnt, dfsn[MAX_V];
vector<int> adj[MAX_V];
vector<int> maxDivCnts;

int dfs(const int now, const int prev) {
	int nowMinDfsn = dfsn[now] = ++dcnt;
	int bccCnt = 0;

	for (const auto& next : adj[now]) {
		if (next == prev)
			continue;

		if (dfsn[next])
			nowMinDfsn = min(nowMinDfsn, dfsn[next]);
		else {
			const int nextMinDfsn = dfs(next, now);
			nowMinDfsn = min(nowMinDfsn, nextMinDfsn);
			if (nextMinDfsn >= dfsn[now])
				++bccCnt;
		}
	}

	maxDivCnts.back() = max(maxDivCnts.back(), bccCnt + (now != prev));

	return nowMinDfsn;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	while (true) {
		cin >> V >> E;

		if (!V && !E)
			break;

		dcnt = 0;

		fill(dfsn, dfsn + V, 0);
		fill(adj, adj + V, vector<int>());

		vector<int>().swap(maxDivCnts);

		for (int i = 0; i < E; ++i) {
			int u, v;
			cin >> u >> v;
			adj[u].emplace_back(v);
			adj[v].emplace_back(u);
		}

		for (int i = 0; i < V; ++i) {
			if (!dfsn[i]) {
				maxDivCnts.push_back(0);
				dfs(i, i);
			}
		}

		cout << *max_element(maxDivCnts.begin(), maxDivCnts.end()) + maxDivCnts.size() - 1 << '\n';
	}

	return 0;
}
