#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

constexpr int MAX_N = 10;
constexpr int MAX_D = 200;

struct Food {
	int limit;
	int amount;

	bool operator<(const Food& rhs) const {
		return limit + amount < rhs.limit + rhs.amount;
	}
};

int T, N, ans;
Food foods[MAX_N];
bool dp[MAX_D + 1];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {

		cin >> N;

		for (int i = 0; i < N; ++i)
			cin >> foods[i].limit >> foods[i].amount;

		sort(foods, foods + N);

		ans = 0;
		memset(dp, 0, sizeof(dp));

		dp[0] = true;

		for (int i = 0; i < N; ++i) {
			const auto& [limit, amount] = foods[i];

			for (int j = limit; j >= 0; --j) {
				if (!dp[j])
					continue;

				dp[j + amount] = true;
				ans = max(ans, j + amount);
			}
		}

		cout << "Case #" << tc << ": " << ans << '\n';
	}

	return 0;
}
