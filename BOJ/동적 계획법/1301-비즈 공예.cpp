#include <iostream>
#include <cstring>
using namespace std;

constexpr int MAX_N = 5;
constexpr int MAX_M = 10;

int N, sum;
int marble[MAX_N + 1];
long long dp[MAX_N + 1][MAX_N + 1][MAX_M + 1][MAX_M + 1][MAX_M + 1][MAX_M + 1][MAX_M + 1];

long long dfs(int level, int prev, int cur) {
	if (level >= sum)
		return 1;

	long long& ret = dp[prev][cur][marble[1]][marble[2]][marble[3]][marble[4]][marble[5]];

	if (ret != -1)
		return ret;

	ret = 0;

	for (int next = 1; next <= N; ++next) {
		if (prev == next || cur == next)
			continue;

		if (!marble[next])
			continue;

		--marble[next];
		ret += dfs(level + 1, cur, next);
		++marble[next];
	}

	return ret;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; ++i) {
		cin >> marble[i];
		sum += marble[i];
	}

	memset(dp, -1, sizeof(dp));

	cout << dfs(0, 0, 0) << '\n';

	return 0;
}
