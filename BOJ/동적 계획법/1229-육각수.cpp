#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

constexpr int INF = 987'654'321;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> dp(N + 1, INF);
	dp[0] = 0;

	int num = 0;

	for (int i = 0; ; ++i) {
		num += 1 + 4 * i;

		if (num > N)
			break;

		for (int j = num; j <= N; ++j)
			dp[j] = min(dp[j], dp[j - num] + 1);
	}

	cout << dp[N] << '\n';

	return 0;
}
