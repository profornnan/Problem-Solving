#include <iostream>
using namespace std;

constexpr int MAX_N = 30;

int N;
int dp[MAX_N + 1];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	dp[0] = dp[1] = 1;

	for (int i = 2; i <= N; ++i)
		dp[i] = dp[i - 1] + dp[i - 2] * 2;

	if (N & 1)
		cout << (dp[N] + dp[(N - 1) / 2]) / 2 << '\n';
	else
		cout << (dp[N] + dp[N / 2] + dp[N / 2 - 1] * 2) / 2 << '\n';

	return 0;
}
