#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

constexpr int MAX_N = 100'000;
constexpr int MOD = 1'000'000'007;

int N, K;
vector<int> adj[MAX_N + 1];
int painted[MAX_N + 1];
int dp[MAX_N + 1][4];

int dfs(const int now, const int prev, const int used) {
	int& ret = dp[now][used];

	if (ret != -1)
		return ret;

	ret = 0;

	for (int color = 1; color <= 3; ++color) {
		if (painted[now] && painted[now] != color)
			continue;

		if (color == used)
			continue;

		long long cnt = 1;

		for (const auto& next : adj[now])
			if (next != prev)
				cnt = (cnt * dfs(next, now, color)) % MOD;

		ret = (ret + cnt) % MOD;
	}

	return ret;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> K;

	for (int i = 0; i < N - 1; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}

	for (int i = 0; i < K; ++i) {
		int idx, color;
		cin >> idx >> color;
		painted[idx] = color;
	}

	memset(dp, -1, sizeof(dp));

	cout << dfs(1, 1, 0) << '\n';

	return 0;
}
