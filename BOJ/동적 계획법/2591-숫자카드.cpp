#include <iostream>
using namespace std;

constexpr int MAX_N = 40;
constexpr int MAX_C = 34;

int N;
int arr[MAX_N + 1];
int dp[MAX_N + 1];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	string str;
	cin >> str;

	N = str.size();

	for (int i = 0; i < N; ++i)
		arr[i + 1] = str[i] - '0';

	dp[0] = dp[1] = 1;

	for (int i = 2; i <= N; ++i) {
		if (arr[i])
			dp[i] += dp[i - 1];

		if (arr[i - 1] && arr[i - 1] * 10 + arr[i] <= MAX_C)
			dp[i] += dp[i - 2];
	}

	cout << dp[N] << '\n';

	return 0;
}
