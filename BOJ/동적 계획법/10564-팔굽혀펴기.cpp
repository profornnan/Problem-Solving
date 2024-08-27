#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

constexpr int MAX_N = 5'000;
constexpr int MAX_M = 10;

int T, N, M;
int scores[MAX_M];
int dp[MAX_N + 1];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> T;

	while (T--) {
		cin >> N >> M;

		for (int i = 0; i < M; ++i)
			cin >> scores[i];

		memset(dp, 0, sizeof(dp));

		dp[0] = 1;

		int ans = 0;
		int cnt = 1;

		while (true) {
			bool exist = false;

			for (int i = N; i >= 0; --i) {
				int res = 0;

				for (int j = 0; j < M; ++j) {
					const int k = i - scores[j] * cnt;

					if (k < 0 || !dp[k])
						continue;

					res = max(res, dp[k] + scores[j]);
				}

				if (res)
					exist = true;

				dp[i] = res;
			}

			if (!exist)
				break;

			ans = max(ans, dp[N]);
			++cnt;
		}

		cout << ans - 1 << '\n';
	}

	return 0;
}
