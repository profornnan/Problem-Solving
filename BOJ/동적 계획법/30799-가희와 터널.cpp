#include <iostream>
using namespace std;

constexpr long long MOD = 998'244'353;
constexpr int C = 7;

int S;
long long dp[C + 1];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> S;

	dp[0] = 1;

	for (int i = 0; i < S; ++i) {
		for (int j = C; j >= 1; --j)
			dp[j] = (dp[j - 1] + dp[j] * (C - 1)) % MOD;

		dp[0] = (dp[0] * C) % MOD;
	}

	cout << dp[C] << '\n';

	return 0;
}
