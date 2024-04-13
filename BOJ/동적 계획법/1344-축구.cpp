#include <iostream>
using namespace std;

constexpr int N = 18;

double dp[N + 1][N + 1][N + 1];

bool prime(int n) {
	if (n < 2)
		return false;

	for (int i = 2; i * i <= n; ++i)
		if (n % i == 0)
			return false;

	return true;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);
	cout << fixed;
	cout.precision(16);

	double A, B;
	cin >> A >> B;

	A /= 100;
	B /= 100;

	dp[0][0][0] = 1.0;

	for (int k = 1; k <= N; ++k) {
		for (int i = 0; i <= k; ++i) {
			for (int j = 0; j <= k; ++j) {
				if (i > 0)
					dp[k][i][j] += dp[k - 1][i - 1][j] * A * (1 - B);

				if (j > 0)
					dp[k][i][j] += dp[k - 1][i][j - 1] * (1 - A) * B;

				if (i > 0 && j > 0)
					dp[k][i][j] += dp[k - 1][i - 1][j - 1] * A * B;

				dp[k][i][j] += dp[k - 1][i][j] * (1 - A) * (1 - B);
			}
		}
	}

	double ans = 0;

	for (int i = 0; i <= N; ++i)
		for (int j = 0; j <= N; ++j)
			if (prime(i) || prime(j))
				ans += dp[N][i][j];

	cout << ans << '\n';

	return 0;
}
