#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

constexpr int MAX_N = 100'000;
constexpr int MAX_L = 100'000;

vector<int> adj[MAX_N + MAX_L + 1];
int dist[MAX_N + MAX_L + 1];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, L;
	cin >> N >> L;

	for (int u = N + 1; u <= N + L; ++u) {
		int v;

		while (true) {
			cin >> v;
			if (v == -1) break;
			adj[u].emplace_back(v);
			adj[v].emplace_back(u);
		}
	}

	int st, en;
	cin >> st >> en;

	queue<int> q;
	memset(dist, -1, sizeof(dist));

	q.push(st);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (const auto& next : adj[now]) {
			if (dist[next] != -1) continue;
			dist[next] = dist[now] + (next > N);
			q.push(next);
		}
	}

	cout << dist[en] << '\n';

	return 0;
}
