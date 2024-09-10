#include <iostream>
#include <algorithm>
using namespace std;

constexpr int MAX_N = 3'000;

int N, B;
int arr[MAX_N];
int dp[MAX_N + 1][2];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> B;

	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	for (int i = 0; i < N; ++i) {
		for (int j = B; j >= 2; --j) {
			dp[j][0] = max(dp[j][0], dp[j][1]);
			dp[j][1] = max(dp[j - 1][0], dp[j - 1][1] + arr[i]);
		}
	}

	cout << max(dp[B][0], dp[B][1]) << '\n';

	return 0;
}
