#include <iostream>
#include <algorithm>
using namespace std;

constexpr int MAX_N = 100'000;

int arr[MAX_N];
int dp[MAX_N][2];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	int ans = dp[0][0] = dp[0][1] = arr[0];

	for (int i = 1; i < N; ++i) {
		dp[i][0] = max(dp[i - 1][0] + arr[i], arr[i]);
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + arr[i]);
		ans = max({ ans, dp[i][0], dp[i][1] });
	}

	cout << ans << '\n';

	return 0;
}
