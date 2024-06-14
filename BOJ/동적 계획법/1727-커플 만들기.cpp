#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

constexpr int MAX_N = 1'000;
constexpr int MAX_M = 1'000;

int N, M;
int boy[MAX_N];
int girl[MAX_M];
int dp[MAX_N + 1][MAX_M + 1];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < N; ++i)
		cin >> boy[i];

	for (int j = 0; j < M; ++j)
		cin >> girl[j];

	sort(boy, boy + N);
	sort(girl, girl + M);

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			if (i == j)
				dp[i][j] = dp[i - 1][j - 1] + abs(boy[i - 1] - girl[i - 1]);
			else if (i > j)
				dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1] + abs(boy[i - 1] - girl[j - 1]));
			else if (i < j)
				dp[i][j] = min(dp[i][j - 1], dp[i - 1][j - 1] + abs(boy[i - 1] - girl[j - 1]));
		}
	}

	cout << dp[N][M] << '\n';

	return 0;
}
