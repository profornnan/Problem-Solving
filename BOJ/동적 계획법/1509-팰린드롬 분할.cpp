#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#define sws ios::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

const int INF = 987654321;
bool is_palindrome[2501][2501];
int dp[2501];

int solve(int idx) {
	if (idx < 0)
		return 0;
	if (dp[idx] != -1)
		return dp[idx];
	int& ret = dp[idx];
	ret = INF;
	for (int i = idx; i >= 0; i--) {
		if (is_palindrome[idx][i]) {
			ret = min(ret, 1 + solve(i - 1));
		}
	}
	return ret;
}

int main(void)
{
	sws;
	freopen("input.txt", "r", stdin);
	string str;
	cin >> str;
	memset(dp, -1, sizeof(dp));
	int len = str.size();
	for (int i = 0; i < len; i++) {
		is_palindrome[i][i] = true;
		for (int j = 0; j < i; j++) {
			if (str[i] == str[j]) is_palindrome[i][j] = is_palindrome[i - 1][j + 1];
			if (i - j == 1) is_palindrome[i][j] |= str[i] == str[i - 1];
		}
	}
	cout << solve(len - 1) << '\n';
	return 0;
}
