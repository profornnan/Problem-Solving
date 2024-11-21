#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

constexpr int MAX_N = 2'000;

int N;
int H[MAX_N];
int dp[MAX_N][MAX_N];

int dfs(const int left, const int right) {
	if (left > right)
		return 0;

	int& ret = dp[left][right];

	if (ret != -1)
		return ret;

	const int cnt = N - right + left;

	return ret = max(dfs(left + 1, right) + H[left] * cnt, dfs(left, right - 1) + H[right] * cnt);
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> H[i];

	memset(dp, -1, sizeof(dp));

	cout << dfs(0, N - 1) << '\n';

	return 0;
}
