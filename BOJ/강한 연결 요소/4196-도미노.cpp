#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

constexpr int MAX_V = 100'000;

int V, E, dcnt, dfsn[MAX_V], scnt, sccn[MAX_V];
vector<int> adj[MAX_V];
bool finished[MAX_V];
stack<int> stk;

int dfs(const int now) {
	int nowMinDfsn = dfsn[now] = ++dcnt;
	stk.push(now);

	for (const auto& next : adj[now]) {
		if (!dfsn[next]) nowMinDfsn = min(nowMinDfsn, dfs(next));
		else if (!finished[next]) nowMinDfsn = min(nowMinDfsn, dfsn[next]);
	}

	if (nowMinDfsn == dfsn[now]) {
		while (true) {
			const int t = stk.top();
			stk.pop();
			sccn[t] = scnt;
			finished[t] = true;
			if (t == now) break;
		}

		++scnt;
	}

	return nowMinDfsn;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int T;
	cin >> T;

	while (T--) {
		cin >> V >> E;

		dcnt = 0;
		scnt = 0;

		fill(dfsn, dfsn + V, 0);
		fill(sccn, sccn + V, 0);
		fill(adj, adj + V, vector<int>());
		fill(finished, finished + V, false);

		for (int i = 0; i < E; ++i) {
			int from, to;
			cin >> from >> to;
			adj[from - 1].push_back(to - 1);
		}

		for (int i = 0; i < V; ++i)
			if (!dfsn[i])
				dfs(i);

		vector<int> indegree(scnt);

		for (int from = 0; from < V; ++from)
			for (const auto& to : adj[from])
				if (sccn[from] != sccn[to])
					++indegree[sccn[to]];

		cout << count(indegree.begin(), indegree.end(), 0) << '\n';
	}

	return 0;
}
