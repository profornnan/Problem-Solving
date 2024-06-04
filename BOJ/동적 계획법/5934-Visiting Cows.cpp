#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

constexpr int MAX_N = 50'000;

int N;
int dp[MAX_N + 1][2];
vector<int> adj[MAX_N + 1];

int dfs(int now, int prev, bool selected) {
	int& ret = dp[now][selected];

	if (ret != -1)
		return ret;

	ret = 0;

	for (const auto& next : adj[now])
		if (next != prev)
			ret += (selected ? dfs(next, now, false) : max(dfs(next, now, false), dfs(next, now, true) + 1));

	return ret;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N - 1; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	memset(dp, -1, sizeof(dp));

	cout << max(dfs(1, 1, false), dfs(1, 1, true) + 1) << '\n';

	return 0;
}
