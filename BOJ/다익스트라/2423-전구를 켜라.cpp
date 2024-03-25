#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

constexpr int INF = 987654321;
constexpr int MAX_N = 500;
constexpr int MAX_M = 500;

// dx, dy, ntileType
const vector<vector<tuple<int, int, int>>> nextTile = {
	{{1, 0, 1}, {0, -1, 1}, {-1, -1, 0}, {-1, 0, 1}, {0, 1, 1}, {1, 1, 0}},
	{{1, 0, 0}, {1, -1, 1}, {0, -1, 0}, {-1, 0, 0}, {-1, 1, 1}, {0, 1, 0}}
};

struct Edge {
	int y;
	int x;
	int tileType;
	int cost;

	bool operator<(const Edge& rhs) const {
		return cost > rhs.cost;
	}
};

int N, M;
int circuit[MAX_N][MAX_M];
int dist[MAX_N][MAX_M][2];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> M;

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			char ch;
			cin >> ch;

			circuit[y][x] = ch == '\\' ? 0 : 1;
			dist[y][x][0] = dist[y][x][1] = INF;
		}
	}

	priority_queue<Edge> pq;

	dist[0][0][0] = circuit[0][0];
	pq.push({ 0, 0, 0, dist[0][0][0] });

	while (!pq.empty()) {
		auto [y, x, tileType, cost] = pq.top();
		pq.pop();

		if (dist[y][x][tileType] < cost)
			continue;

		for (const auto& [dx, dy, ntileType] : nextTile[tileType]) {
			int ny = y + dy;
			int nx = x + dx;

			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue;

			int ncost = cost + (circuit[ny][nx] != ntileType);

			if (dist[ny][nx][ntileType] <= ncost)
				continue;

			dist[ny][nx][ntileType] = ncost;
			pq.push({ ny, nx, ntileType, ncost });
		}
	}

	if (dist[N - 1][M - 1][0] == INF)
		cout << "NO SOLUTION\n";
	else
		cout << dist[N - 1][M - 1][0] << '\n';

	return 0;
}
