#include <iostream>
#include <algorithm>
using namespace std;

constexpr int INF = 21e8;
constexpr int MAX_N = 4'000;

int N, M;
bool adj[MAX_N + 1][MAX_N + 1];
int cnt[MAX_N + 1];
int ans = INF;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < M; ++i) {
		int u, v;
		cin >> u >> v;

		adj[u][v] = adj[v][u] = true;
		++cnt[u];
		++cnt[v];
	}

	for (int a = 1; a <= N; ++a) {
		for (int b = a + 1; b <= N; ++b) {
			if (!adj[a][b])
				continue;

			for (int c = b + 1; c <= N; ++c) {
				if (!adj[a][c] || !adj[b][c])
					continue;

				ans = min(ans, cnt[a] + cnt[b] + cnt[c] - 6);
			}
		}
	}

	cout << (ans == INF ? -1 : ans) << '\n';

	return 0;
}
