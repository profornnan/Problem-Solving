#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

constexpr int INF = 987654321;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, M, R;
	cin >> N >> M >> R;

	vector<vector<int>> dist(N, vector<int>(N, INF));
	vector<int> items(N);

	for (int& item : items)
		cin >> item;

	for (int i = 0; i < N; ++i)
		dist[i][i] = 0;

	for (int i = 0; i < R; ++i) {
		int u, v, c;
		cin >> u >> v >> c;
		--u; --v;
		dist[u][v] = dist[v][u] = c;
	}

	for (int k = 0; k < N; ++k)
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	int maxItemCnt = 0;

	for (int st = 0; st < N; ++st) {
		int itemCnt = 0;

		for (int en = 0; en < N; ++en)
			if (dist[st][en] <= M)
				itemCnt += items[en];

		maxItemCnt = max(maxItemCnt, itemCnt);
	}

	cout << maxItemCnt << '\n';

	return 0;
}
