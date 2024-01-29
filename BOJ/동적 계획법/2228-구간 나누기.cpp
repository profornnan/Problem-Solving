#include <iostream>
#include <algorithm>
using namespace std;

constexpr int INF = 987654321;
constexpr int MAX_N = 100;

int N, M;
int psum[MAX_N + 1];
int dp[MAX_N + 1][MAX_N / 2 + 1];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; ++i) {
		int num;
		cin >> num;
		psum[i] = psum[i - 1] + num;
	}

	for (int i = 0; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			dp[i][j] = -INF;

	dp[1][1] = psum[1];

	for (int i = 2; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			dp[i][j] = dp[i - 1][j];

			if (j == 1)
				dp[i][j] = max(dp[i][j], psum[i]);

			for (int k = 2; k <= i; ++k)
				dp[i][j] = max(dp[i][j], dp[k - 2][j - 1] + psum[i] - psum[k - 1]);
		}
	}

	cout << dp[N][M] << '\n';

	return 0;
}
