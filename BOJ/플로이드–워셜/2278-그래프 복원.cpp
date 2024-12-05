#include <iostream>
using namespace std;

constexpr int MAX_N = 100;
constexpr int MAX_D = 500;

int N, M;
int dist[MAX_N + 1][MAX_N + 1];
int path[MAX_N + 1][MAX_N + 1];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> M;

	if (M > N * (N - 1) / 2) {
		cout << "0\n";
		return 0;
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = i + 1; j <= N; ++j) {
			cin >> dist[i][j];
			dist[j][i] = dist[i][j];
			path[i][j] = j;
			path[j][i] = i;
		}
	}

	for (int k = 1; k <= N; ++k) {
		for (int i = 1; i <= N; ++i) {
			if (i == k)
				continue;

			for (int j = 1; j <= N; ++j) {
				if (j == k)
					continue;

				if (dist[i][j] == dist[i][k] + dist[k][j])
					path[i][j] = path[i][k];
			}
		}
	}

	int cnt = 0;

	for (int i = 1; i <= N; ++i)
		for (int j = i + 1; j <= N; ++j)
			if (path[i][j] == j)
				++cnt;

	if (cnt > M) {
		cout << "0\n";
		return 0;
	}

	cout << "1\n";

	for (int i = 1; i <= N; ++i) {
		for (int j = i + 1; j <= N; ++j) {
			if (path[i][j] == j)
				cout << i << ' ' << j << ' ' << dist[i][j] << '\n';
			else if (cnt < M) {
				cout << i << ' ' << j << ' ' << MAX_D << '\n';
				++cnt;
			}
		}
	}

	return 0;
}
