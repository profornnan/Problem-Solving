#include <iostream>
#include <string>
#include <cstring>
using namespace std;

constexpr int MAX_L = 200;

int T;
string a, b, c;
int dp[MAX_L + 1][MAX_L + 1];

int dfs(const int i, const int j) {
	if (i >= a.size() && j >= b.size())
		return 1;

	int& ret = dp[i][j];

	if (ret != -1)
		return ret;

	if (i < a.size() && a[i] == c[i + j] && dfs(i + 1, j))
		return ret = 1;

	if (j < b.size() && b[j] == c[i + j] && dfs(i, j + 1))
		return ret = 1;

	return ret = 0;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cin >> a >> b >> c;
		memset(dp, -1, sizeof(dp));
		cout << "Data set " << tc << ": " << (dfs(0, 0) ? "yes" : "no") << '\n';
	}

	return 0;
}
