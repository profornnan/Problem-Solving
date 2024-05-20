#include <iostream>
#include <algorithm>
using namespace std;

constexpr int MAX_N = 20'000;

int N, M;
long long K;
long long orange[MAX_N + 1];
long long dp[MAX_N + 1];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> M >> K;

	for (int i = 1; i <= N; ++i)
		cin >> orange[i];

	for (int i = 1; i <= N; ++i) {
		long long big = orange[i];
		long long small = orange[i];

		dp[i] = dp[i - 1] + K;

		for (int j = i - 1; j >= max(1, i - M + 1); --j) {
			big = max(big, orange[j]);
			small = min(small, orange[j]);

			dp[i] = min(dp[i], dp[j - 1] + K + (i - j + 1) * (big - small));
		}
	}

	cout << dp[N] << '\n';

	return 0;
}
