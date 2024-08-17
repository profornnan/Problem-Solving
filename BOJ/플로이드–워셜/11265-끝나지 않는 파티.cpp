#include <iostream>
using namespace std;

constexpr int MAX_N = 500;

int N, M;
int dist[MAX_N + 1][MAX_N + 1];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			cin >> dist[i][j];

	for (int k = 1; k <= N; ++k)
		for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= N; ++j)
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];

	for (int i = 0; i < M; ++i) {
		int s, e, t;
		cin >> s >> e >> t;
		cout << (dist[s][e] <= t ? "Enjoy other party" : "Stay here") << '\n';
	}

	return 0;
}
