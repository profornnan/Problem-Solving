#include <iostream>
#include <queue>
#define sws ios::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

struct Edge {
	int y;
	int x;
	int cost;
	bool operator<(Edge next) const {
		if (cost < next.cost)
			return false;
		if (cost > next.cost)
			return true;
		return false;
	}
};

int dx[]{ 1, 0, -1, 0 };
int dy[]{ 0, -1, 0, 1 };

const int MAX = 987654321;
int N, M;
int MAP[1000][1000];
int dist[1000][1000];

int dijkstra() {
	if (MAP[0][0] == -1)
		return -1;

	priority_queue<Edge> pq;
	pq.push({ 0, 0, MAP[0][0] });
	dist[0][0] = MAP[0][0];

	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();

		if (dist[now.y][now.x] < now.cost) continue;

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
			if (MAP[ny][nx] == -1) continue;

			int ncost = dist[now.y][now.x] + MAP[ny][nx];

			if (dist[ny][nx] <= ncost) continue;

			pq.push({ ny, nx, ncost });
			dist[ny][nx] = ncost;
		}
	}

	if (dist[N - 1][M - 1] == MAX)
		return -1;

	return dist[N - 1][M - 1];
}

int main(void) {
	sws;

	cin >> N >> M;
	
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> MAP[y][x];
			dist[y][x] = MAX;
		}
	}

	cout << dijkstra() << '\n';

	return 0;
}
