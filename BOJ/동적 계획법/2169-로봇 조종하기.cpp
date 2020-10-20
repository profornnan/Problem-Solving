#include <iostream>
#include <algorithm>
#define sws ios::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

int N, M;
int area[1000][1000];
int dp[1000][1000];
int line[2][1000];

int main(void) {
	sws;
	freopen("input.txt", "r", stdin);
	cin >> N >> M;

	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			cin >> area[y][x];

	dp[0][0] = area[0][0];

	for (int x = 1; x < M; x++)
		dp[0][x] = dp[0][x - 1] + area[0][x];

	for (int y = 1; y < N; y++) {
		for (int x = 0; x < M; x++)
			line[0][x] = line[1][x] = dp[y - 1][x] + area[y][x];

		for (int x = 1; x < M; x++)
			line[0][x] = max(line[0][x], line[0][x - 1] + area[y][x]);

		for (int x = M - 2; x >= 0; x--)
			line[1][x] = max(line[1][x], line[1][x + 1] + area[y][x]);

		for (int x = 0; x < M; x++)
			dp[y][x] = max(line[0][x], line[1][x]);
	}

	cout << dp[N - 1][M - 1] << '\n';

	return 0;
}
