#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

constexpr int INF = 987654321;
constexpr int MAX_N = 20;

int N;
int cost[MAX_N][MAX_N];
int dp[1 << MAX_N];

int dfs(int person, int state) {
	if (person >= N)
		return 0;

	int& ret = dp[state];

	if (ret != -1)
		return ret;

	ret = INF;

	for (int work = 0; work < N; ++work)
		if (!(state & (1 << work)))
			ret = min(ret, cost[person][work] + dfs(person + 1, state | (1 << work)));

	return ret;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> cost[i][j];

	memset(dp, -1, sizeof(dp));

	cout << dfs(0, 0) << '\n';

	return 0;
}
