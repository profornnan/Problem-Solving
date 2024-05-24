#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

constexpr int MAX_N = 300;
constexpr int MAX_M = 300;

int N, M, K;
vector<pair<int, int>> adj[MAX_N + 1];
int dp[MAX_M + 1][MAX_N + 1];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> M >> K;

	for (int i = 0; i < K; ++i) {
		int from, to, cost;
		cin >> from >> to >> cost;

		if (from > to)
			continue;

		adj[from].push_back({ to, cost });
	}

	for (const auto& [next, cost] : adj[1])
		dp[2][next] = max(dp[2][next], cost);

	for (int cnt = 2; cnt < M; ++cnt)
		for (int now = 1; now <= N; ++now)
			if (dp[cnt][now])
				for (const auto& [next, cost] : adj[now])
					dp[cnt + 1][next] = max(dp[cnt + 1][next], dp[cnt][now] + cost);

	int ans = 0;

	for (int cnt = 2; cnt <= M; ++cnt)
		ans = max(ans, dp[cnt][N]);

	cout << ans << '\n';

	return 0;
}
