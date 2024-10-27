#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

constexpr int MAX_N = 2'000;

int N;
int arr[MAX_N];
long long dp[MAX_N][MAX_N];

long long dfs(const int st, const int en) {
	const int cnt = (en - st + 1 + N) % N;

	if (cnt == 0)
		return 0;

	long long& ret = dp[st][en];

	if (ret != -1)
		return ret;

	const int left = (st - 1 + N) % N;
	const int right = (en + 1) % N;

	if (cnt & 1)
		return ret = arr[left] > arr[right] ? dfs(left, en) : dfs(st, right);

	return ret = max(arr[left] + dfs(left, en), arr[right] + dfs(st, right));
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	memset(dp, -1, sizeof(dp));

	long long ans = 0;

	for (int i = 0; i < N; ++i)
		ans = max(ans, arr[i] + dfs(i, i));

	cout << ans << '\n';

	return 0;
}
