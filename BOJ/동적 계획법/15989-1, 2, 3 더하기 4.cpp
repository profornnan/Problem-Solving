#include <iostream>
#include <vector>
using namespace std;

constexpr int MAX_N = 10'000;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	vector<int> dp(MAX_N + 1, 1);

	for (int n = 2; n <= MAX_N; ++n)
		dp[n] += dp[n - 2];

	for (int n = 3; n <= MAX_N; ++n)
		dp[n] += dp[n - 3];

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		int n;
		cin >> n;
		cout << dp[n] << '\n';
	}

	return 0;
}
