#include <iostream>
#include <queue>
using namespace std;
using pii = pair<int, int>;

constexpr int MAX_N = 1'000;
constexpr int INF = 1'000'000'000;
constexpr int TRANS = 1'000'000;

int company[MAX_N];
int adj[MAX_N][MAX_N];
int dist[MAX_N];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		cin >> company[i];
		dist[i] = INF;
	}

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> adj[i][j];

	priority_queue<pii> pq;

	dist[0] = 0;
	pq.push({ 0, 0 });

	while (!pq.empty()) {
		auto [d, now] = pq.top();
		d *= -1;
		pq.pop();

		if (dist[now] < d)
			continue;

		for (int next = 0; next < N; ++next) {
			if (!adj[now][next])
				continue;

			int nd = dist[now] + adj[now][next] + (company[now] ^ company[next]) * TRANS;

			if (dist[next] <= nd)
				continue;

			dist[next] = nd;
			pq.push({ -nd, next });
		}
	}

	cout << dist[M] / TRANS << ' ' << dist[M] % TRANS << '\n';

	return 0;
}
