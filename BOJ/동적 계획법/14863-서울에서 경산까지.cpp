#include <iostream>
#include <algorithm>
using namespace std;

constexpr int MAX_N = 100;
constexpr int MAX_K = 100'000;

struct Info {
	int hour;
	int profit;
};

int N, K;
Info walk[MAX_N + 1];
Info bicycle[MAX_N + 1];
int dp[MAX_N + 1][MAX_K + 1];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> K;

	for (int i = 1; i <= N; ++i)
		cin >> walk[i].hour >> walk[i].profit >> bicycle[i].hour >> bicycle[i].profit;

	dp[1][walk[1].hour] = max(dp[1][walk[1].hour], walk[1].profit);
	dp[1][bicycle[1].hour] = max(dp[1][bicycle[1].hour], bicycle[1].profit);

	for (int i = 2; i <= N; ++i) {
		for (int j = 1; j <= K; ++j) {
			if (!dp[i - 1][j])
				continue;

			if (j + walk[i].hour <= K)
				dp[i][j + walk[i].hour] = max(dp[i][j + walk[i].hour], dp[i - 1][j] + walk[i].profit);

			if (j + bicycle[i].hour <= K)
				dp[i][j + bicycle[i].hour] = max(dp[i][j + bicycle[i].hour], dp[i - 1][j] + bicycle[i].profit);
		}
	}

	cout << *max_element(dp[N] + 1, dp[N] + K + 1) << '\n';

	return 0;
}
