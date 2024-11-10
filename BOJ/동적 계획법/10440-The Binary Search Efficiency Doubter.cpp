#include <iostream>
using namespace std;

constexpr int MAX_N = 10'000'000;

int T, N;
int dp[MAX_N + 1];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	dp[1] = 1;

	for (int i = 2; i <= MAX_N; ++i)
		dp[i] = dp[(i - 1) / 2] + dp[(i - 1) / 2 + ((i - 1) & 1)] + i;

	while (cin >> N)
		cout << "Case " << ++T << ": " << dp[N] << '\n';

	return 0;
}
