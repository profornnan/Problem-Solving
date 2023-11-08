#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

constexpr int MAX_N = 1000;

enum {
	STRAWBERRY,
	CHOCO,
	BANANA
};

int N;
int MAP[MAX_N + 1][MAX_N + 1];
int dp[MAX_N + 1][MAX_N + 1][3];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	for (int y = 1; y <= N; ++y)
		for (int x = 1; x <= N; ++x)
			cin >> MAP[y][x];

	for (int y = 1; y <= N; ++y) {
		for (int x = 1; x <= N; ++x) {
			const int milk = MAP[y][x];

			dp[y][x][STRAWBERRY] = milk == STRAWBERRY
				? max(dp[y][x - 1][BANANA], dp[y - 1][x][BANANA]) + 1
				: max(dp[y][x - 1][STRAWBERRY], dp[y - 1][x][STRAWBERRY]);

			dp[y][x][CHOCO] = milk == CHOCO && dp[y][x][STRAWBERRY]
				? max(dp[y][x - 1][STRAWBERRY], dp[y - 1][x][STRAWBERRY]) + 1
				: max(dp[y][x - 1][CHOCO], dp[y - 1][x][CHOCO]);

			dp[y][x][BANANA] = milk == BANANA && dp[y][x][CHOCO]
				? max(dp[y][x - 1][CHOCO], dp[y - 1][x][CHOCO]) + 1
				: max(dp[y][x - 1][BANANA], dp[y - 1][x][BANANA]);
		}
	}

	cout << max({ dp[N][N][STRAWBERRY], dp[N][N][CHOCO], dp[N][N][BANANA] }) << '\n';

	return 0;
}
