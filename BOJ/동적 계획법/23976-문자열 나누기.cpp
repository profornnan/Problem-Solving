#include <iostream>
#include <string>
using namespace std;

constexpr int MOD = 1'000'000'007;
constexpr int MAX_K = 2'500;

int N, K;
string str;
int dp[MAX_K + 1][2];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> K >> str;

	dp[1][0] = str[0] == '0' ? 1 : 0;
	dp[1][1] = str[0] != '0' ? 1 : 0;

	for (int i = 1; i < N; ++i) {
		for (int j = K; j >= 1; --j) {
			if (str[i] == '0') {
				dp[j][0] = (dp[j - 1][0] + dp[j - 1][1]) % MOD;
			}
			else {
				dp[j][0] = 0;
				dp[j][1] = ((dp[j - 1][0] + dp[j - 1][1]) % MOD + dp[j][1]) % MOD;
			}
		}
	}

	cout << (dp[K][0] + dp[K][1]) % MOD << '\n';

	return 0;
}
