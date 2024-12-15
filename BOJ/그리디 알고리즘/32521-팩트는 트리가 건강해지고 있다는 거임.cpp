#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

constexpr int MAX_N = 100'000;

int N, K, ans;
int health[MAX_N + 1];
vector<int> adj[MAX_N + 1];

int dfs(const int now, const int prev) {
	int ret = health[now];

	vector<int> sub;

	for (const auto& next : adj[now]) {
		if (next == prev)
			continue;

		const int cnt = dfs(next, now);

		if (cnt)
			sub.push_back(cnt);
	}

	sort(sub.begin(), sub.end());

	int idx = 0;

	while (idx < sub.size() && ret + sub[idx] <= K) {
		ret += sub[idx];
		++idx;
	}

	ans += sub.size() - idx;

	return ret;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> K;

	for (int i = 1; i <= N; ++i)
		cin >> health[i];

	for (int i = 0; i < N - 1; ++i) {
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 1);

	cout << ans << '\n';

	return 0;
}
