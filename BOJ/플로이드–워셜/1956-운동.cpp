#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

constexpr int INF = 987654321;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int V, E;
	cin >> V >> E;

	vector<vector<int>> dist(V, vector<int>(V, INF));

	for (int i = 0; i < E; ++i) {
		int from, to, cost;
		cin >> from >> to >> cost;
		--from; --to;
		dist[from][to] = cost;
	}

	for (int k = 0; k < V; ++k)
		for (int i = 0; i < V; ++i)
			for (int j = 0; j < V; ++j)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	int ans = INF;

	for (int i = 0; i < V; ++i)
		ans = min(ans, dist[i][i]);

	if (ans == INF)
		ans = -1;

	cout << ans << '\n';

	return 0;
}
