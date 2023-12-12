#include <iostream>
#include <algorithm>
using namespace std;

constexpr int MAX_N = 1000;

int N;
int score[MAX_N + 1];
int dp[MAX_N + 1];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> score[i];

	for (int i = 0; i < N; ++i) {
		int maxScore = score[i];
		int minScore = score[i];

		for (int j = i; j >= 0; --j) {
			maxScore = max(maxScore, score[j]);
			minScore = min(minScore, score[j]);
			dp[i + 1] = max(dp[i + 1], dp[j] + maxScore - minScore);
		}
	}

	cout << dp[N] << '\n';

	return 0;
}
