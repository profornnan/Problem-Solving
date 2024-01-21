#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

constexpr int MAX_N = 50;

string str;
int dp[MAX_N][MAX_N];

int dfs(int left, int right) {
	if (left >= right)
		return 0;

	int& ret = dp[left][right];

	if (ret != -1)
		return ret;

	ret = min({ dfs(left + 1, right) + 1, dfs(left, right - 1) + 1, dfs(left + 1, right - 1) + (str[left] != str[right]) });

	return ret;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> str;

	memset(dp, -1, sizeof(dp));

	int ans = dfs(0, str.size() - 1);

	for (int i = 0; i < str.size(); ++i) {
		for (int j = i + 1; j < str.size(); ++j) {
			if (str[i] == str[j])
				continue;

			memset(dp, -1, sizeof(dp));

			swap(str[i], str[j]);
			ans = min(ans, dfs(0, str.size() - 1) + 1);
			swap(str[i], str[j]);
		}
	}

	cout << ans << '\n';

	return 0;
}
