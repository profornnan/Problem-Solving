#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

constexpr int MAX_N = 5'000;

int N, M;
int height[MAX_N + 1];
int dp[MAX_N + 1];
vector<int> adj[MAX_N + 1];

int dfs(int now) {
	int& ret = dp[now];

	if (ret)
		return ret;

	ret = 1;

	for (const auto& next : adj[now])
		ret = max(ret, dfs(next) + 1);

	return ret;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
		cin >> height[i];

	for (int i = 1; i <= M; ++i) {
		int u, v;
		cin >> u >> v;
		height[u] < height[v] ? adj[u].push_back(v) : adj[v].push_back(u);
	}

	for (int i = 1; i <= N; ++i)
		cout << dfs(i) << '\n';

	return 0;
}
