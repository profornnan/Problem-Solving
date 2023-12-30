#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

constexpr int MAX_N = 15;
constexpr int MAX_C = 9;

int N;
int dp[MAX_N][MAX_C + 1][1 << MAX_N];
int costs[MAX_N][MAX_N];

int dfs(int last, int cost, int state) {
	int& ret = dp[last][cost][state];

	if (ret != -1)
		return ret;

	ret = 1;

	for (int now = 0; now < N; ++now) {
		if (now == last)
			continue;

		if (state & (1 << now))
			continue;

		if (costs[last][now] < cost)
			continue;

		ret = max(ret, dfs(now, costs[last][now], state | (1 << now)) + 1);
	}

	return ret;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; ++i) {
		string row;
		cin >> row;

		for (int j = 0; j < N; ++j)
			costs[i][j] = row[j] - '0';
	}

	memset(dp, -1, sizeof(dp));

	cout << dfs(0, 0, 1 << 0) << '\n';

	return 0;
}
