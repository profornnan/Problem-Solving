#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

constexpr int MAX_N = 20;
constexpr int MAX_K = 20;

int N, K;
int s1, s2;
int order[MAX_K];
int dp[MAX_K][MAX_N + 1][MAX_N + 1];

int dfs(int cnt, int o1, int o2) {
	if (cnt >= K)
		return 0;

	int& ret = dp[cnt][o1][o2];

	if (ret != -1)
		return ret;

	ret = min(abs(order[cnt] - o1) + dfs(cnt + 1, order[cnt], o2), abs(order[cnt] - o2) + dfs(cnt + 1, o1, order[cnt]));

	return ret;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> s1 >> s2 >> K;

	for (int i = 0; i < K; ++i)
		cin >> order[i];

	memset(dp, -1, sizeof(dp));

	cout << dfs(0, s1, s2) << '\n';

	return 0;
}
