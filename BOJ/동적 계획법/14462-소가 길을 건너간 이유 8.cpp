#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

constexpr int MAX_N = 1'000;

int N;
int A[MAX_N + 1];
int B[MAX_N + 1];
int dp[MAX_N + 1][MAX_N + 1];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; ++i)
		cin >> A[i];

	for (int i = 1; i <= N; ++i)
		cin >> B[i];

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			dp[i][j] = abs(A[i] - B[j]) <= 4 ? dp[i - 1][j - 1] + 1 : max(dp[i - 1][j], dp[i][j - 1]);

	cout << dp[N][N] << '\n';

	return 0;
}
