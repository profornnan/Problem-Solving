#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

constexpr int MAX_L = 500;

int N;
string str;
int dp[MAX_L][MAX_L];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> str;
	N = str.size();

	for (int len = 1; len < N; ++len) {
		for (int st = 0; st + len < N; ++st) {
			int en = st + len;

			if ((str[st] == 'a' && str[en] == 't') || (str[st] == 'g' && str[en] == 'c'))
				dp[st][en] = dp[st + 1][en - 1] + 2;

			for (int mid = st; mid < en; ++mid)
				dp[st][en] = max(dp[st][en], dp[st][mid] + dp[mid + 1][en]);
		}
	}

	cout << dp[0][N - 1] << '\n';

	return 0;
}
