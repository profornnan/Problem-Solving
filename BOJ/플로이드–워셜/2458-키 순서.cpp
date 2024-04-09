#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> graph(N, vector<int>(N));

	for (int i = 0; i < M; ++i) {
		int u, v;
		cin >> u >> v;
		graph[u - 1][v - 1] = true;
	}

	for (int k = 0; k < N; ++k)
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				if (graph[i][k] && graph[k][j])
					graph[i][j] = true;

	int ans = 0;

	for (int i = 0; i < N; ++i) {
		int cnt = 0;

		for (int j = 0; j < N; ++j)
			if (graph[i][j] || graph[j][i])
				++cnt;

		if (cnt == N - 1)
			++ans;
	}

	cout << ans << '\n';

	return 0;
}
