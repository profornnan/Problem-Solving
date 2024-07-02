#include <iostream>
#include <algorithm>
using namespace std;

constexpr int MAX_N = 5'000;

int N;
int seq[MAX_N];
int dp[MAX_N][MAX_N];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> seq[i];

	for (int cnt = 1; cnt < N; ++cnt) {
		for (int st = 0; st + cnt < N; ++st) {
			const int en = st + cnt;

			dp[st][en] = seq[st] == seq[en] ? dp[st + 1][en - 1] : min(dp[st][en - 1], dp[st + 1][en]) + 1;
		}
	}

	cout << dp[0][N - 1] << '\n';

	return 0;
}
