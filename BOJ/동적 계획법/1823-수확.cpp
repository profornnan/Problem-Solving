#include <iostream>
#include <algorithm>
using namespace std;

constexpr int MAX_N = 2'000;

int N;
int value[MAX_N];
int dp[MAX_N][MAX_N];

int dfs(const int left, const int right) {
	if (left > right)
		return 0;

	if (dp[left][right])
		return dp[left][right];

	const int cnt = N - right + left;

	return dp[left][right] = max(dfs(left + 1, right) + value[left] * cnt, dfs(left, right - 1) + value[right] * cnt);
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> value[i];

	cout << dfs(0, N - 1) << '\n';

	return 0;
}
