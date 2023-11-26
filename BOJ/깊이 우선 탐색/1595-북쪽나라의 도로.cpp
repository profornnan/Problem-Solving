#include <iostream>
#include <vector>
using namespace std;
using pii = pair<int, int>;

constexpr int MAX_N = 10'000;

vector<pii> adj[MAX_N + 1];
bool visited[MAX_N + 1];
int maxDist, maxNode;

void dfs(int now, int dist) {
	visited[now] = true;

	if (dist > maxDist) {
		maxDist = dist;
		maxNode = now;
	}

	for (const auto& [next, cost] : adj[now]) {
		if (visited[next])
			continue;

		dfs(next, dist + cost);
	}

	visited[now] = false;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int u, v, c;

	while (cin >> u >> v >> c) {
		adj[u].push_back({ v, c });
		adj[v].push_back({ u, c });
	}

	dfs(1, 0);
	maxDist = 0;

	dfs(maxNode, 0);
	cout << maxDist << '\n';

	return 0;
}
