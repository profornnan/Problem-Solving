#include <iostream>
#include <cstring>
using namespace std;

constexpr int MOD = 1'000'000'000;
constexpr int MASK = (1 << 10) - 1;
int dp[101][10][1 << 10];

int dfs(int level, int last, int state) {
	if (level == 0)
		return state == MASK;

	int& ret = dp[level][last][state];

	if (ret != -1)
		return ret;

	ret = 0;

	if (last + 1 <= 9)
		ret = (ret + dfs(level - 1, last + 1, state | (1 << last + 1))) % MOD;

	if (0 <= last - 1)
		ret = (ret + dfs(level - 1, last - 1, state | (1 << last - 1))) % MOD;

	return ret % MOD;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, sum = 0;
	cin >> N;

	memset(dp, -1, sizeof(dp));

	for (int i = 1; i <= 9; i++)
		sum = (sum + dfs(N - 1, i, 1 << i)) % MOD;

	cout << sum << '\n';

	return 0;
}
