#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

struct Edge {
	int to;
	int cost;
	bool operator < (const Edge& next) const {
		return cost > next.cost;
	}
};

const int INF = 987654321;

int N, M;
int S, D;
vector<vector<Edge>> adj;
vector<int> dist;
vector<vector<int>> path;

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	while (true) {
		cin >> N >> M;
		if (N == 0 && M == 0) break;

		cin >> S >> D;

		adj = vector<vector<Edge>>(N);
		dist = vector<int>(N, INF);
		path = vector<vector<int>>(N);

		for (int i = 0; i < M; i++) {
			int u, v, p;
			cin >> u >> v >> p;
			adj[u].push_back({ v, p });
		}

		priority_queue<Edge> pq;
		pq.push({ S, 0 });
		dist[S] = 0;

		while (!pq.empty()) {
			Edge now = pq.top();
			pq.pop();

			if (dist[now.to] < now.cost) continue;

			for (Edge next : adj[now.to]) {
				int ncost = dist[now.to] + next.cost;

				if (dist[next.to] > ncost) {
					vector<int>(1, now.to).swap(path[next.to]);
					pq.push({ next.to, ncost });
					dist[next.to] = ncost;
				}
				else if (dist[next.to] == ncost)
					path[next.to].push_back(now.to);
			}
		}

		if (dist[D] == INF) {
			cout << "-1\n";
			continue;
		}

		set<pair<int, int>> us;

		queue<int> q;
		vector<int> visited(N);
		visited[D] = 1;
		q.push(D);

		while (!q.empty()) {
			int now = q.front();
			q.pop();

			for (int next : path[now]) {
				us.insert({ next, now });

				if (visited[next] == 1) continue;

				visited[next] = 1;
				q.push(next);
			}
		}

		dist = vector<int>(N, INF);
		pq.push({ S, 0 });
		dist[S] = 0;

		while (!pq.empty()) {
			Edge now = pq.top();
			pq.pop();

			if (dist[now.to] < now.cost) continue;

			for (Edge next : adj[now.to]) {
				if (us.find({ now.to, next.to }) != us.end()) continue;

				int ncost = dist[now.to] + next.cost;

				if (dist[next.to] <= ncost) continue;

				pq.push({ next.to, ncost });
				dist[next.to] = ncost;
			}
		}

		if (dist[D] == INF)
			cout << "-1\n";
		else
			cout << dist[D] << '\n';
	}

	return 0;
}
