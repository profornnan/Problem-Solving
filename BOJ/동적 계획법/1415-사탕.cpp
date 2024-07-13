#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	int sum = 0;
	int zeroCnt = 1;
	vector<int> prices;

	for (int i = 0; i < N; ++i) {
		int price;
		cin >> price;

		if (price == 0) {
			++zeroCnt;
			continue;
		}

		prices.emplace_back(price);
		sum += price;
	}

	sort(prices.begin(), prices.end());
	prices.push_back(0);

	vector<long long> dp(sum + 1);
	dp[0] = zeroCnt;

	int now = prices[0];
	int cnt = 0;

	for (const auto& price : prices) {
		if (now == price) {
			++cnt;
			continue;
		}

		for (int i = sum; i >= now; --i) {
			for (int j = 1; j <= cnt; ++j) {
				if (i - now * j < 0)
					break;

				dp[i] += dp[i - now * j];
			}
		}

		now = price;
		cnt = 1;
	}

	long long ans = 0;
	vector<bool> prime(sum + 1, true);

	prime[0] = prime[1] = false;

	for (long long i = 2; i <= sum; ++i) {
		if (!prime[i])
			continue;

		for (long long j = i * i; j <= sum; j += i)
			prime[j] = false;

		ans += dp[i];
	}

	cout << ans << '\n';

	return 0;
}
