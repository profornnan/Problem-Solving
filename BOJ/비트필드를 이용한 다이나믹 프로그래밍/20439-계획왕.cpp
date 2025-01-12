#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

constexpr int MAX_N = 11;
constexpr int MAX_K = 12;
constexpr int MAX_T = 1440;

struct Time {
	int st;
	int en;
};

int N, K;
Time remain[MAX_N + 1];
int todo[MAX_K];
int dp[1 << MAX_K][MAX_T + 1];

bool dfs(const int state, const int t) {
	if (state == (1 << K) - 1)
		return 1;

	int& ret = dp[state][t];

	if (ret != -1)
		return ret;

	ret = 0;

	for (int i = 0; i < K; ++i) {
		if (state & (1 << i))
			continue;

		for (int j = 0; j <= N; ++j) {
			auto [st, en] = remain[j];
			st = max(st, t);
			en = max(en, t);

			if (st + todo[i] <= en)
				ret |= dfs(state | (1 << i), st + todo[i]);
		}
	}

	return ret;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> K;

	for (int i = 0; i < N; ++i)
		cin >> remain[i].en >> remain[i + 1].st;

	remain[N].en = MAX_T;

	for (int i = 0; i < K; ++i)
		cin >> todo[i];

	memset(dp, -1, sizeof(dp));

	cout << (dfs(0, 0) ? "GOOD" : "BAD") << '\n';

	return 0;
}
