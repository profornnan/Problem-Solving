#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

constexpr int INF = 987654321;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;

		vector<int> files(N + 1);
		vector<int> psum(N + 1);
		vector<vector<int>> dp(N + 1, vector<int>(N + 1, INF));

		for (int i = 1; i <= N; ++i) {
			cin >> files[i];
			dp[i][i] = 0;
			psum[i] = psum[i - 1] + files[i];
		}

		for (int k = 1; k < N; ++k) {
			for (int i = 1; i <= N - k; ++i) {
				for (int j = i; j < i + k; ++j)
					dp[i][i + k] = min(dp[i][i + k], dp[i][j] + dp[j + 1][i + k]);

				dp[i][i + k] += psum[i + k] - psum[i - 1];
			}
		}

		cout << dp[1][N] << '\n';
	}

	return 0;
}
