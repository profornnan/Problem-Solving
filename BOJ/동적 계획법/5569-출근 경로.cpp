#include <iostream>
using namespace std;

constexpr int MOD = 100'000;
constexpr int MAX_H = 100;
constexpr int MAX_W = 100;

int H, W;
int dp[MAX_H + 1][MAX_W + 1][2][2];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> H >> W;

	for (int i = 1; i <= H; ++i)
		dp[i][1][0][0] = 1;

	for (int i = 1; i <= W; ++i)
		dp[1][i][1][0] = 1;

	for (int i = 2; i <= H; ++i) {
		for (int j = 2; j <= W; ++j) {
			dp[i][j][0][0] = (dp[i - 1][j][0][0] + dp[i - 1][j][0][1]) % MOD;
			dp[i][j][0][1] = dp[i - 1][j][1][0];
			dp[i][j][1][0] = (dp[i][j - 1][1][0] + dp[i][j - 1][1][1]) % MOD;
			dp[i][j][1][1] = dp[i][j - 1][0][0];
		}
	}

	cout << (dp[H][W][0][0] + dp[H][W][0][1] + dp[H][W][1][0] + dp[H][W][1][1]) % MOD << '\n';

	return 0;
}
