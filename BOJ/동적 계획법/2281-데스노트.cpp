#include <iostream>
#include <algorithm>
using namespace std;

constexpr int INF = 987654321;
constexpr int MAX_N = 1'000;

int N, M;
int len[MAX_N + 1];
int dp[MAX_N + 1];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> M;

	len[0] = M;

	for (int i = 1; i <= N; ++i)
		cin >> len[i];

	for (int i = 1; i <= N; ++i) {
		dp[i] = INF;

		int remain = M + 1;

		for (int j = i - 1; j >= 0; --j) {
			remain -= len[j] + 1;

			if (remain < 0)
				break;

			dp[i] = min(dp[i], dp[j] + remain * remain);
		}
	}

	int ans = dp[N];
	int sum = len[N];

	for (int i = N - 1; i >= 0; --i) {
		sum += len[i] + 1;

		if (sum > M)
			break;

		ans = min(ans, dp[i]);
	}

	cout << ans << '\n';

	return 0;
}
