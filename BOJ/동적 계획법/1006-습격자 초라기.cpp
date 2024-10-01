#include <iostream>
#include <algorithm>
using namespace std;

constexpr int MAX_N = 10'000;
constexpr int MAX_W = 10'000;

int T, N, W;
int arr[2][MAX_N + 1];
int dp[MAX_N + 1][3];

void solve() {
	for (int i = 2; i <= N; ++i) {
		const int up = arr[0][i - 1] + arr[0][i] <= W ? 1 : 2;
		const int down = arr[1][i - 1] + arr[1][i] <= W ? 1 : 2;
		const int ver = arr[0][i] + arr[1][i] <= W ? 1 : 2;

		dp[i][0] = min(dp[i - 1][1] + up, dp[i - 1][2] + 1);
		dp[i][1] = min(dp[i - 1][0] + down, dp[i - 1][2] + 1);
		dp[i][2] = min({ dp[i - 1][2] + ver, dp[i - 2][2] + up + down, dp[i - 1][0] + 1 + down, dp[i - 1][1] + up + 1 });
	}
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cin >> N >> W;

		for (int i = 0; i < 2; ++i)
			for (int j = 1; j <= N; ++j)
				cin >> arr[i][j];

		dp[1][0] = dp[1][1] = 1;
		dp[1][2] = arr[0][1] + arr[1][1] <= W ? 1 : 2;

		solve();

		int ans = dp[N][2];

		if (N == 1) {
			cout << ans << '\n';
			continue;
		}

		if (arr[0][N] + arr[0][1] <= W) {
			dp[1][0] = dp[1][1] = 1;
			dp[1][2] = 2;

			arr[0][1] += MAX_W;
			solve();
			arr[0][1] -= MAX_W;

			ans = min(ans, dp[N][1]);
		}

		if (arr[1][N] + arr[1][1] <= W) {
			dp[1][0] = dp[1][1] = 1;
			dp[1][2] = 2;

			arr[1][1] += MAX_W;
			solve();
			arr[1][1] -= MAX_W;

			ans = min(ans, dp[N][0]);
		}

		if (arr[0][N] + arr[0][1] <= W && arr[1][N] + arr[1][1] <= W) {
			dp[1][0] = dp[1][1] = 1;
			dp[1][2] = 2;

			arr[0][1] += MAX_W;
			arr[1][1] += MAX_W;
			solve();
			arr[1][1] -= MAX_W;
			arr[0][1] -= MAX_W;

			ans = min(ans, dp[N - 1][2]);
		}

		cout << ans << '\n';
	}

	return 0;
}
