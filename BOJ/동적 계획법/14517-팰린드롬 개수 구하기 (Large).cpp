#include <iostream>
#include <vector>
#include <string>
using namespace std;

constexpr int MOD = 10'007;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	string str;
	cin >> str;

	const int N = str.size();
	vector<vector<int>> dp(N, vector<int>(N));

	for (int i = 0; i < N; ++i)
		dp[i][i] = 1;

	for (int cnt = 1; cnt < N; ++cnt) {
		for (int st = 0; st + cnt < N; ++st) {
			const int en = st + cnt;

			if (str[st] == str[en])
				dp[st][en] = (dp[st + 1][en] + dp[st][en - 1] + 1) % MOD;
			else
				dp[st][en] = (dp[st + 1][en] + dp[st][en - 1] - dp[st + 1][en - 1] + MOD) % MOD;
		}
	}

	cout << dp[0][N - 1] << '\n';

	return 0;
}
