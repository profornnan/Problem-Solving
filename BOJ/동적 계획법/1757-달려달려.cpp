#include <iostream>
#include <algorithm>
using namespace std;

constexpr int MAX_N = 10'000;
constexpr int MAX_M = 500;

int N, M;
int d[MAX_N + 1];
int dp[MAX_N + 1][MAX_M + 1];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
		cin >> d[i];

	for (int i = 1; i <= N; ++i) {
		dp[i][0] = max({ dp[i][0], dp[i - 1][0], dp[i - 1][1] });

		for (int j = 1; j <= M; ++j) {
			dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + d[i]);
			if (i + j <= N) dp[i + j][0] = max(dp[i + j][0], dp[i][j]);
		}
	}

	cout << dp[N][0] << '\n';

	return 0;
}
