#include <iostream>
#include <vector>
using namespace std;

constexpr int INF = 987654321;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, M, K;
	cin >> N >> M;

	vector<vector<int>> dist(N + 1, vector<int>(N + 1, INF));

	for (int i = 1; i <= N; ++i)
		dist[i][i] = 0;

	for (int i = 0; i < M; ++i) {
		int u, v, b;
		cin >> u >> v >> b;

		dist[u][v] = 0;
		dist[v][u] = !b;
	}

	cin >> K;

	for (int k = 1; k <= N; ++k)
		for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= N; ++j)
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];

	for (int i = 0; i < K; ++i) {
		int s, e;
		cin >> s >> e;
		cout << dist[s][e] << '\n';
	}

	return 0;
}
