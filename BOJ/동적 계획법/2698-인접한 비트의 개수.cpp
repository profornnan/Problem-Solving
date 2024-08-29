#include <iostream>
using namespace std;

constexpr int MAX_N = 100;
constexpr int MAX_K = 100;

int T, N, K;
int dp[MAX_N + 1][MAX_K + 1][2];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> T;

	dp[0][0][0] = 1;

	for (int i = 1; i <= MAX_N; ++i) {
		dp[i][0][0] = dp[i - 1][0][0] + dp[i - 1][0][1];
		dp[i][0][1] = dp[i - 1][0][0];

		for (int j = 1; j < i; ++j) {
			dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];
			dp[i][j][1] = dp[i - 1][j][0] + dp[i - 1][j - 1][1];
		}
	}

	while (T--) {
		cin >> N >> K;
		cout << dp[N][K][0] + dp[N][K][1] << '\n';
	}

	return 0;
}
