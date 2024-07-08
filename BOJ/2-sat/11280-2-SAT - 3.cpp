#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

constexpr int MAX_N = 10'000;

int N, M, dcnt, dfsn[MAX_N * 2], scnt, sccn[MAX_N * 2];
vector<int> adj[MAX_N * 2];
bool finished[MAX_N * 2];
stack<int> stk;

inline int getSign(const int num) {
	return (num > 0) - (num < 0);
}

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

	cin >> N >> M;

	for (int i = 0; i < M; ++i) {
		int u, v;
		cin >> u >> v;

		u = (u * getSign(u) - 1) * 2 + (u < 0);
		v = (v * getSign(v) - 1) * 2 + (v < 0);

		adj[u + (u % 2 ? -1 : 1)].emplace_back(v);
		adj[v + (v % 2 ? -1 : 1)].emplace_back(u);
	}

	for (int i = 0; i < N * 2; ++i)
		if (!dfsn[i])
			dfs(i);

	bool possible = true;

	for (int i = 0; i < N; ++i) {
		if (sccn[i * 2] == sccn[i * 2 + 1]) {
			possible = false;
			break;
		}
	}

	cout << possible << '\n';

	return 0;
}
