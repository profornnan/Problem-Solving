#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int T, K;
	cin >> T >> K;

	vector<pair<int, int>> coins(K);
	vector<int> dp(T + 1);

	for (auto& [amt, cnt] : coins)
		cin >> amt >> cnt;

	dp[0] = 1;

	for (const auto& [amt, cnt] : coins) {
		for (int i = T; i >= 0; --i) {
			for (int j = 1; j <= cnt; ++j) {
				if (i - amt * j < 0)
					break;

				dp[i] += dp[i - amt * j];
			}
		}
	}

	cout << dp[T] << '\n';

	return 0;
}
