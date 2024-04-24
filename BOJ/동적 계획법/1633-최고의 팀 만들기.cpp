#include <iostream>
#include <algorithm>
using namespace std;

constexpr int MAX_N = 1'000;
constexpr int M = 15;

struct Player {
	int white;
	int black;
};

int N;
Player player[MAX_N + 1];
int dp[MAX_N + 1][M + 1][M + 1];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	while (cin >> player[N + 1].white >> player[N + 1].black)
		++N;

	dp[1][1][0] = player[1].white;
	dp[1][0][1] = player[1].black;

	for (int i = 2; i <= N; ++i) {
		for (int j = 0; j <= M; ++j) {
			for (int k = 0; k <= M; ++k) {
				if (j + k > i)
					continue;

				dp[i][j][k] = dp[i - 1][j][k];

				if (j > 0)
					dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + player[i].white);

				if (k > 0)
					dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + player[i].black);
			}
		}
	}

	cout << dp[N][M][M] << '\n';

	return 0;
}
