#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int N, K;
		cin >> N >> K;

		vector<vector<int>> dp(N + 1, vector<int>(K + 1));
		vector<int> volume(N + 1);
		vector<int> cost(N + 1);

		for (int i = 1; i <= N; i++)
			cin >> volume[i] >> cost[i];

		for (int i = 1; i <= N; i++) {
			for (int j = 0; j <= K; j++) {
				dp[i][j] = dp[i - 1][j];
				if (volume[i] > j) continue;
				dp[i][j] = max(dp[i][j], dp[i - 1][j - volume[i]] + cost[i]);
			}
		}

		cout << '#' << tc << ' ' << dp[N][K] << '\n';
	}

	return 0;
}
