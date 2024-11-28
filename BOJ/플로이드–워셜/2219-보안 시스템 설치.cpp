#include <iostream>
#include <vector>
using namespace std;

constexpr int INF = 987'654'321;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> dist(N + 1, vector<int>(N + 1, INF));

	for (int i = 1; i <= N; ++i)
		dist[i][i] = 0;

	for (int i = 0; i < M; ++i) {
		int u, v, c;
		cin >> u >> v >> c;
		dist[u][v] = dist[v][u] = c;
	}

	for (int k = 1; k <= N; ++k)
		for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= N; ++j)
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];

	int ans = 0;
	int minSum = INF;

	for (int i = 1; i <= N; ++i) {
		int sum = 0;

		for (int j = 1; j <= N; ++j)
			sum += dist[i][j];

		if (minSum > sum) {
			ans = i;
			minSum = sum;
		}
	}

	cout << ans << '\n';

	return 0;
}
