#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	vector<int> coins(N);
	vector<int> dp(K + 1);

	for (int& coin : coins)
		cin >> coin;

	dp[0] = 1;

	for (int coin : coins)
		for (int k = coin; k <= K; ++k)
			dp[k] += dp[k - coin];

	cout << dp[K] << '\n';

	return 0;
}
