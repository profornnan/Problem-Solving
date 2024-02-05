#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

constexpr int INF = 987654321;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	vector<int> dp(K + 1, INF);
	dp[0] = 0;

	for (int n = 0; n < N; ++n) {
		int coin;
		cin >> coin;

		for (int i = coin; i <= K; ++i)
			dp[i] = min(dp[i], dp[i - coin] + 1);
	}

	cout << (dp[K] == INF ? -1 : dp[K]) << '\n';

	return 0;
}
