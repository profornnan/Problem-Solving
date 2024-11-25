#include <iostream>
#include <cstring>
using namespace std;

constexpr int MAX_S = 100;

int T, R, Y, B;
double dp[MAX_S + 2][MAX_S + 2][MAX_S + 2];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cout << fixed;
	cout.precision(12);

	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cin >> R >> Y >> B;

		memset(dp, 0, sizeof(dp));

		dp[R][Y][B] = 1;

		for (int r = R; r >= 0; --r) {
			for (int y = Y; y >= 0; --y) {
				for (int b = B; b >= 0; --b) {
					int div = r * (y + 1) + r * b + (y + 1) * b;

					if (div)
						dp[r][y][b] += dp[r][y + 1][b] * r * (y + 1) / div;

					div = r * y + r * (b + 1) + y * (b + 1);

					if (div)
						dp[r][y][b] += dp[r][y][b + 1] * y * (b + 1) / div;

					div = (r + 1) * y + (r + 1) * b + y * b;

					if (div)
						dp[r][y][b] += dp[r + 1][y][b] * b * (r + 1) / div;
				}
			}
		}

		double rSum = 0;
		double ySum = 0;
		double bSum = 0;

		for (int r = R; r >= 0; --r)
			rSum += dp[r][0][0];

		for (int y = Y; y >= 0; --y)
			ySum += dp[0][y][0];

		for (int b = B; b >= 0; --b)
			bSum += dp[0][0][b];

		const double totalSum = rSum + ySum + bSum;

		cout << rSum / totalSum << ' ' << ySum / totalSum << ' ' << bSum / totalSum << '\n';
	}

	return 0;
}
