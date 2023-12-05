#include <iostream>
#include <algorithm>
using namespace std;

constexpr int MAX_N = 8;

int N;
int S[MAX_N];
int W[MAX_N];
int ans;

void dfs(int idx, int cnt) {
	if (idx >= N) {
		ans = max(ans, cnt);
		return;
	}

	if (S[idx] <= 0 || cnt == N - 1) {
		dfs(idx + 1, cnt);
		return;
	}

	for (int i = 0; i < N; ++i) {
		if (i == idx)
			continue;

		if (S[i] <= 0)
			continue;

		S[idx] -= W[i];
		S[i] -= W[idx];

		dfs(idx + 1, cnt + (S[idx] <= 0) + (S[i] <= 0));

		S[i] += W[idx];
		S[idx] += W[i];
	}
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> S[i] >> W[i];

	dfs(0, 0);

	cout << ans << '\n';

	return 0;
}
