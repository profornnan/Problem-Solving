#include <iostream>
#include <string>
using namespace std;

constexpr int MOD = 1'000'000'007;
constexpr int S = 4;
const string suffix = "ROCK";

int N;
string str;
int dp[S + 1];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> str;

	dp[S] = 1;

	for (int i = N - 1; i >= 0; --i) {
		dp[0] = dp[0] * 2 % MOD;

		for (int j = S - 1; j >= 0; --j)
			if (str[i] == suffix[j])
				dp[j] = (dp[j] + dp[j + 1]) % MOD;
	}

	cout << dp[0] << '\n';

	return 0;
}
