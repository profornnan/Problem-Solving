#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

constexpr int MAX_N = 100'000;

int N, S;
vector<pair<int, int>> adj[MAX_N + 1];
int sum, maxLen;

void dfs(const int now, const int prev, const int len) {
	maxLen = max(maxLen, len);

	for (const auto& [next, cost] : adj[now])
		if (next != prev)
			dfs(next, now, len + cost);
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> S;

	for (int i = 0; i < N - 1; ++i) {
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back({ v, c });
		adj[v].push_back({ u, c });
		sum += c;
	}

	dfs(S, S, 0);

	cout << sum * 2 - maxLen << '\n';

	return 0;
}
