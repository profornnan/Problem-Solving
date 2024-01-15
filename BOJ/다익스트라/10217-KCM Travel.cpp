#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

constexpr int INF = 987654321;
constexpr int MAX_N = 100;
constexpr int MAX_M = 10'000;

struct Edge {
	int to;
	int cost;
	int hour;

	bool operator<(const Edge& rhs) const {
		return hour > rhs.hour;
	}
};

vector<Edge> adj[MAX_N + 1];
int dist[MAX_N + 1][MAX_M + 1];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		int N, M, K;
		cin >> N >> M >> K;

		for (int n = 1; n <= N; ++n) {
			adj[n].clear();

			for (int m = 0; m <= M; ++m)
				dist[n][m] = INF;
		}

		for (int k = 0; k < K; ++k) {
			int from, to, cost, hour;
			cin >> from >> to >> cost >> hour;
			adj[from].push_back({ to, cost, hour });
		}

		for (int n = 1; n <= N; ++n) {
			sort(adj[n].begin(), adj[n].end(), [](const Edge& lhs, const Edge& rhs) {
				return lhs.hour < rhs.hour;
			});
		}

		priority_queue<Edge> pq;

		pq.push({ 1, 0, 0 });
		dist[1][0] = 0;

		while (!pq.empty()) {
			Edge now = pq.top();
			pq.pop();

			if (dist[now.to][now.cost] < now.hour)
				continue;

			for (const auto& next : adj[now.to]) {
				int ncost = now.cost + next.cost;
				int nhour = now.hour + next.hour;

				if (ncost > M)
					continue;

				if (dist[next.to][ncost] <= nhour)
					continue;

				pq.push({ next.to, ncost, nhour });

				for (int m = ncost; m <= M; ++m) {
					if (dist[next.to][m] <= nhour)
						break;

					dist[next.to][m] = nhour;
				}
			}
		}

		int ans = INF;

		for (int m = 0; m <= M; ++m)
			ans = min(ans, dist[N][m]);

		if (ans == INF)
			cout << "Poor KCM\n";
		else
			cout << ans << '\n';
	}

	return 0;
}
