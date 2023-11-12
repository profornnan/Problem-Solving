#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

constexpr int MAX_N = 100;
constexpr int MAX_M = 10;
constexpr int MAX_P = 20;

int N, M;
int P[MAX_N];
int dp[MAX_N][MAX_M + 1][MAX_N * MAX_P + 1];

int dfs(int day, int remain, int dirt) {
	if (day >= N)
		return 0;

	int& ret = dp[day][remain][dirt];

	if (ret != -1)
		return ret;

	ret = dfs(day + 1, remain, dirt + P[day]);

	if (remain)
		ret = min(ret, dfs(day + 1, remain - 1, 0));

	return ret + dirt * P[day];
}

void path(int day, int remain, int dirt) {
	if (day >= N)
		return;

	if (dp[day][remain][dirt] == dp[day + 1][remain - 1][0]) {
		cout << day + 1 << ' ';
		path(day + 1, remain - 1, 0);
	}
	else
		path(day + 1, remain, dirt + P[day]);
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < N; ++i)
		cin >> P[i];

	memset(dp, -1, sizeof(dp));

	cout << dfs(0, M, 0) << '\n';

	path(0, M, 0);

	return 0;
}
