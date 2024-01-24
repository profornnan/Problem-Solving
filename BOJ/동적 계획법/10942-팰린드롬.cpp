#include <iostream>
#include <cstring>
using namespace std;

constexpr int MAX_N = 2'000;

int N, M;
int arr[MAX_N];
int dp[MAX_N][MAX_N];

int dfs(int st, int en) {
	if (st >= en)
		return 1;

	int& ret = dp[st][en];

	if (ret != -1)
		return ret;

	return ret = arr[st] == arr[en] ? dfs(st + 1, en - 1) : 0;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	cin >> M;

	for (int i = 0; i < M; ++i) {
		int st, en;
		cin >> st >> en;
		cout << dfs(st - 1, en - 1) << '\n';
	}

	return 0;
}
