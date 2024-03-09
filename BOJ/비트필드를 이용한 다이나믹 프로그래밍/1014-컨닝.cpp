#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int T;
	cin >> T;

	while (T--) {
		int N, M;
		cin >> N >> M;

		vector<int> classroom(N + 1);

		for (int y = 1; y <= N; ++y) {
			for (int x = 0; x < M; ++x) {
				char ch;
				cin >> ch;
				classroom[y] = (classroom[y] << 1) + (ch == '.' ? 0 : 1);
			}
		}

		vector<pair<int, int>> masks;

		for (int mask = 0; mask < (1 << M); ++mask) {
			int now = mask;
			int cnt = 0;
			bool isPossible = true;

			while (now) {
				if ((now & 3) == 3) {
					isPossible = false;
					break;
				}

				if (now & 1)
					++cnt;

				now >>= 1;
			}

			if (isPossible)
				masks.push_back({ mask, cnt });
		}

		vector<vector<int>> dp(N + 1, vector<int>(masks.size()));

		for (int y = 1; y <= N; ++y) {
			for (int i = 0; i < masks.size(); ++i) {
				const auto& [mask, cnt] = masks[i];

				if (mask & classroom[y - 1])
					continue;

				for (int j = 0; j < masks.size(); ++j) {
					const auto& [nmask, ncnt] = masks[j];

					if (nmask & classroom[y])
						continue;

					if ((nmask << 1) & mask)
						continue;

					if ((nmask >> 1) & mask)
						continue;

					dp[y][j] = max(dp[y][j], dp[y - 1][i] + ncnt);
				}
			}
		}

		cout << *max_element(dp[N].begin(), dp[N].end()) << '\n';
	}

	return 0;
}
