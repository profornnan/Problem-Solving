#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

constexpr int INF = 21e8;
constexpr int MAX_N = 1'000;

int T, N, P;
int X[MAX_N + 1][2];
long long dp[MAX_N + 1][2];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cin >> N >> P;

		for (int i = 1; i <= N; ++i) {
			X[i][0] = INF;
			X[i][1] = 0;

			for (int j = 0; j < P; ++j) {
				int x;
				cin >> x;

				X[i][0] = min(X[i][0], x);
				X[i][1] = max(X[i][1], x);
			}
		}

		for (int i = 1; i <= N; ++i) {
			dp[i][0] = min(dp[i - 1][0] + abs(X[i][0] - X[i - 1][1]), dp[i - 1][1] + abs(X[i][0] - X[i - 1][0])) + X[i][1] - X[i][0];
			dp[i][1] = min(dp[i - 1][0] + abs(X[i][1] - X[i - 1][1]), dp[i - 1][1] + abs(X[i][1] - X[i - 1][0])) + X[i][1] - X[i][0];
		}

		cout << "Case #" << tc << ": " << min(dp[N][0], dp[N][1]) << '\n';
	}

	return 0;
}
