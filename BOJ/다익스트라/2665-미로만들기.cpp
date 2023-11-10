#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

constexpr int INF = 987654321;
constexpr int dx[]{ 1, 0, -1, 0 };
constexpr int dy[]{ 0, -1, 0, 1 };

enum {
	BLACK = '0',
	WHITE = '1'
};

struct Edge {
	int y;
	int x;
	int cost;
	bool operator<(const Edge& next) const {
		return cost > next.cost;
	}
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	vector<string> MAP(N);
	vector<vector<int>> dist(N, vector<int>(N, INF));
	priority_queue<Edge> pq;

	for (auto& row : MAP)
		cin >> row;

	dist[0][0] = 0;
	pq.push({ 0, 0, 0 });

	while (!pq.empty()) {
		const auto [y, x, cost] = pq.top();
		pq.pop();

		if (dist[y][x] < cost)
			continue;

		for (int dir = 0; dir < 4; ++dir) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N)
				continue;

			int ncost = cost + (MAP[ny][nx] == WHITE ? 0 : 1);

			if (dist[ny][nx] <= ncost)
				continue;

			dist[ny][nx] = ncost;
			pq.push({ ny, nx, ncost });
		}
	}

	cout << dist[N - 1][N - 1] << '\n';

	return 0;
}
