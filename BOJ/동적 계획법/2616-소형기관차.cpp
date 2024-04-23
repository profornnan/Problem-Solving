#include <iostream>
#include <algorithm>
using namespace std;

constexpr int MAX_N = 50'000;

int N, K;
int psum[MAX_N + 1];
int dp[4][MAX_N + 1];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; ++i) {
		cin >> psum[i];
		psum[i] += psum[i - 1];
	}

	cin >> K;

	for (int i = 1; i <= 3; ++i)
		for (int j = i * K; j <= N - (3 - i) * K; ++j)
			dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - K] + psum[j] - psum[j - K]);

	cout << dp[3][N] << '\n';

	return 0;
}
