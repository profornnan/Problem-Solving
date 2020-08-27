#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define sws ios::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

const int INF = 987654321;
int N, E, V1, V2;
vector<vector<pair<int, int> > > adj;  // node, weight

long long dijkstra(int start, int end) {
	vector<int> dist(N + 1, INF);
	dist[start] = 0;
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, start));
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (dist[now] < cost)
			continue;
		for (int i = 0; i < adj[now].size(); i++) {
			int next = adj[now][i].first;
			int n_dist = cost + adj[now][i].second;
			if (dist[next] > n_dist) {
				dist[next] = n_dist;
				pq.push(make_pair(-n_dist, next));
			}
		}
	}
	return dist[end];
}

int main(void)
{
	sws;
	freopen("input.txt", "r", stdin);
	cin >> N >> E;
	adj = vector<vector<pair<int, int> > >(N + 1);
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back(make_pair(b, c));
		adj[b].push_back(make_pair(a, c));
	}
	cin >> V1 >> V2;

	long long ans = min(dijkstra(1, V1) + dijkstra(V1, V2) + dijkstra(V2, N), dijkstra(1, V2) + dijkstra(V2, V1) + dijkstra(V1, N));
	
	if (ans >= INF)
		cout << "-1\n";
	else
		cout << ans << '\n';

	return 0;
}
