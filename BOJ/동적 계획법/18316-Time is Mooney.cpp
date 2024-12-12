#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

constexpr int MAX_N = 1'000;
constexpr int MAX_T = 1'000;

int N, M, C;
int value[MAX_N + 1];
int dp[2][MAX_N + 1];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> M >> C;

	for (int i = 1; i <= N; ++i)
		cin >> value[i];

	vector<pair<int, int>> edges;

	for (int i = 0; i < M; ++i) {
		int from, to;
		cin >> from >> to;
		edges.push_back({ from, to });
	}

	int ans = 0;
	memset(dp, -1, sizeof(dp));

	dp[0][1] = 0;

	for (int t = 1; t <= MAX_T; ++t) {
		const int now = t % 2;
		memset(dp[now], -1, sizeof(dp[now]));

		for (const auto& [from, to] : edges)
			if (dp[1 - now][from] >= 0)
				dp[now][to] = max(dp[now][to], dp[1 - now][from] + value[to]);

		ans = max(ans, dp[now][1] - C * t * t);
	}

	cout << ans << '\n';

	return 0;
}
