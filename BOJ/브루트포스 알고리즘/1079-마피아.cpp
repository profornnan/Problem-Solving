#include <iostream>
using namespace std;

constexpr int INF = 21e8;
constexpr int MAX_N = 16;

int N;
int guilt[MAX_N + 1];
int dg[MAX_N][MAX_N];
int mafia, ans;

void dfs(const int day, const int remain, const int state) {
	if (ans == N / 2)
		return;

	if (state & (1 << mafia) || remain == 1) {
		ans = ans > day ? ans : day;
		return;
	}

	if (remain & 1) {
		int maxIdx = N;

		for (int i = 0; i < N; ++i)
			if (!(state & (1 << i)) && guilt[maxIdx] < guilt[i])
				maxIdx = i;

		dfs(day, remain - 1, state | (1 << maxIdx));
	}
	else {
		for (int i = 0; i < N; ++i) {
			if (state & (1 << i) || i == mafia)
				continue;

			for (int j = 0; j < N; ++j)
				guilt[j] += dg[i][j];

			dfs(day + 1, remain - 1, state | (1 << i));

			for (int j = 0; j < N; ++j)
				guilt[j] -= dg[i][j];
		}
	}
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> guilt[i];

	guilt[N] = -INF;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> dg[i][j];

	cin >> mafia;

	dfs(0, N, 0);

	cout << ans << '\n';

	return 0;
}
