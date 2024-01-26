#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

constexpr int INF = 987654321;
constexpr int MAX_L = 1'000;

int N, M;
string src, tar;
int dp[MAX_L + 1][MAX_L + 1][2];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	getline(cin, src);
	getline(cin, tar);

	N = src.size();
	M = tar.size();

	dp[0][0][0] = 0;
	dp[0][0][1] = INF;

	for (int j = 1; j <= M; ++j) {
		dp[0][j][0] = INF;
		dp[0][j][1] = 1;
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j <= i; ++j)
			dp[i + 1][j][0] = dp[i + 1][j][1] = INF;

		for (int j = i; j < M; ++j) {
			dp[i + 1][j + 1][0] = src[i] == tar[j] ? min(dp[i][j][0], dp[i][j][1]) : INF;
			dp[i + 1][j + 1][1] = min(dp[i + 1][j][0] + 1, dp[i + 1][j][1]);
		}
	}

	int res = min(dp[N][M][0], dp[N][M][1]);

	cout << (res == INF ? -1 : res) << '\n';

	return 0;
}
