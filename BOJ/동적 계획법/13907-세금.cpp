#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

constexpr int INF = 987654321;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, M, K;
	int st, en;

	cin >> N >> M >> K;
	cin >> st >> en;

	vector<vector<pair<int, int>>> adj(N + 1);
	vector<int> taxSum(K + 1);

	for (int i = 0; i < M; ++i) {
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back({ v, c });
		adj[v].push_back({ u, c });
	}

	for (int i = 1; i <= K; ++i) {
		cin >> taxSum[i];
		taxSum[i] += taxSum[i - 1];
	}

	vector<vector<int>> dp(N + 1, vector<int>(N + 1, INF));
	dp[0][st] = 0;

	for (int cnt = 1; cnt <= N; ++cnt)
		for (int u = 1; u <= N; ++u)
			for (const auto& [v, cost] : adj[u])
				dp[cnt][u] = min(dp[cnt][u], dp[cnt - 1][v] + cost);

	for (const auto& tax : taxSum) {
		int ans = INF;

		for (int cnt = 1; cnt <= N; ++cnt)
			ans = min(ans, dp[cnt][en] + cnt * tax);

		cout << ans << '\n';
	}

	return 0;
}
