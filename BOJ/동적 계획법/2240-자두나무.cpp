#include <iostream>
#include <algorithm>
using namespace std;

constexpr int MAX_P = 2;
constexpr int MAX_T = 1000;
constexpr int MAX_W = 30;

int T, W;
int drop[MAX_T + 1];
int dp[MAX_P + 1][MAX_T + 1][MAX_W + 1];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> T >> W;

	for (int t = 1; t <= T; ++t)
		cin >> drop[t];

	for (int t = 1; t <= T; ++t)
		dp[1][t][0] = dp[1][t - 1][0] + (drop[t] == 1);

	for (int t = 1; t <= T; ++t) {
		for (int w = 1; w <= W; ++w) {
			dp[1][t][w] = max(dp[1][t - 1][w], dp[2][t - 1][w - 1]) + (drop[t] == 1);
			dp[2][t][w] = max(dp[1][t - 1][w - 1], dp[2][t - 1][w]) + (drop[t] == 2);
		}
	}

	int ans = 0;

	for (int w = 0; w <= W; ++w)
		ans = max({ ans, dp[1][T][w], dp[2][T][w] });

	cout << ans << '\n';

	return 0;
}
