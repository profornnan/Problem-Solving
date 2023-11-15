#include <iostream>
#include <vector>
using namespace std;

constexpr int MAX_M = 10'000;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		int N, M;
		cin >> N;

		vector<int> coins(N);

		for (auto& coin : coins)
			cin >> coin;

		cin >> M;

		vector<int> dp(M + 1);
		dp[0] = 1;

		for (const auto& coin : coins)
			for (int now = coin; now <= M; ++now)
				dp[now] += dp[now - coin];

		cout << dp[M] << '\n';
	}

	return 0;
}
