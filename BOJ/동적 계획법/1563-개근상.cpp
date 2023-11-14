#include <iostream>
#include <cstring>
using namespace std;

constexpr int MOD = 1'000'000;
constexpr int MAX_N = 1'000;

int N;
int dp[MAX_N][2][3];

int dfs(int day, int late, int absent) {
	if (late >= 2 || absent >= 3)
		return 0;

	if (day >= N)
		return 1;

	int& ret = dp[day][late][absent];

	if (ret != -1)
		return ret;

	return ret = (dfs(day + 1, late, 0) + dfs(day + 1, late + 1, 0) + dfs(day + 1, late, absent + 1)) % MOD;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	memset(dp, -1, sizeof(dp));

	cout << dfs(0, 0, 0) << '\n';

	return 0;
}
