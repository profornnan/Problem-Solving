#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

constexpr int INF = 987654321;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	vector<vector<int>> dist(N + 1, vector<int>(N + 1, INF));

	while (true) {
		int u, v;
		cin >> u >> v;

		if (u == -1 && v == -1)
			break;

		dist[u][v] = dist[v][u] = 1;
	}

	for (int i = 1; i <= N; ++i)
		dist[i][i] = 0;

	for (int k = 1; k <= N; ++k)
		for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= N; ++j)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	vector<int> score(N + 1);

	for (int i = 1; i <= N; ++i)
		score[i] = *max_element(dist[i].begin() + 1, dist[i].end());

	int ans = score[1];
	int cnt = 1;

	for (int i = 2; i <= N; ++i) {
		if (ans > score[i]) {
			ans = score[i];
			cnt = 1;
		}
		else if (ans == score[i])
			++cnt;
	}

	cout << ans << ' ' << cnt << '\n';

	for (int i = 1; i <= N; ++i)
		if (ans == score[i])
			cout << i << ' ';
	cout << '\n';

	return 0;
}
