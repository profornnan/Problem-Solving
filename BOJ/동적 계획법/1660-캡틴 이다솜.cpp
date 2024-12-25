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

	for (int i = 1; ; ++i) {
		const int num = i * (i + 1) * (i + 2) / 6;

		if (num > N)
			break;

		for (int j = num; j <= N; ++j)
			dp[j] = min(dp[j], dp[j - num] + 1);
	}

	cout << dp[N] << '\n';

	return 0;
}
