#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

constexpr int MAX_N = 1'000'000;

enum {
	ADOPTER,
	LAGGARD
};

int N;
vector<int> adj[MAX_N + 1];
bool visited[MAX_N + 1];
int dp[MAX_N + 1][2];

void dfs(int now) {
	visited[now] = true;
	dp[now][ADOPTER] = 1;

	for (const auto& next : adj[now]) {
		if (visited[next])
			continue;

		dfs(next);

		dp[now][LAGGARD] += dp[next][ADOPTER];
		dp[now][ADOPTER] += min(dp[next][ADOPTER], dp[next][LAGGARD]);
	}
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1);

	cout << min(dp[1][ADOPTER], dp[1][LAGGARD]) << '\n';

	return 0;
}
