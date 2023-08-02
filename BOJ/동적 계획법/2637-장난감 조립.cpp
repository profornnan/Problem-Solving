#include <iostream>
#include <vector>
using namespace std;
using pii = pair<int, int>;

constexpr int MAX_N = 100;

int N, M;
vector<pii> adj[MAX_N + 1];
bool visited[MAX_N + 1];
int totalCnt[MAX_N + 1][MAX_N + 1];

void dfs(int now, int cnt) {
	visited[now] = true;
	totalCnt[now][now] = 1;

	for (const auto& [next, weight] : adj[now]) {
		if (!visited[next])
			dfs(next, cnt * weight);

		for (int i = 1; i <= N; ++i)
			totalCnt[now][i] += totalCnt[next][i] * weight;
	}
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 1; i <= M; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ v, w });
	}

	dfs(N, 1);

	for (int i = 1; i <= N; ++i)
		if (!adj[i].size())
			cout << i << ' ' << totalCnt[N][i] << '\n';

	return 0;
}
