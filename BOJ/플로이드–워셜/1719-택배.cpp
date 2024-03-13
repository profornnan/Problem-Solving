#include <iostream>
using namespace std;

constexpr int INF = 987654321;
constexpr int MAX_N = 200;

int N, M;
int dist[MAX_N + 1][MAX_N + 1];
int path[MAX_N + 1][MAX_N + 1];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j)
			dist[i][j] = INF;
		dist[i][i] = 0;
	}

	for (int i = 0; i < M; ++i) {
		int u, v, c;
		cin >> u >> v >> c;
		dist[u][v] = dist[v][u] = c;
		path[u][v] = v;
		path[v][u] = u;
	}

	for (int k = 1; k <= N; ++k) {
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					path[i][j] = path[i][k];
				}
			}
		}
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j)
			if (i == j)
				cout << "- ";
			else
				cout << path[i][j] << ' ';
		cout << '\n';
	}

	return 0;
}
