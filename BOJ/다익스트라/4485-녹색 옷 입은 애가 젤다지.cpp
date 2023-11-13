#include <iostream>
#include <queue>
using namespace std;

struct Edge {
	int y;
	int x;
	int cost;
	bool operator<(const Edge& rhs) const {
		return cost > rhs.cost;
	}
};

constexpr int INF = 987654321;
constexpr int MAX_N = 125;
constexpr int dx[]{ 1, 0, -1, 0 };
constexpr int dy[]{ 0, -1, 0, 1 };

int N;
int MAP[MAX_N][MAX_N];
int dist[MAX_N][MAX_N];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	for (int tc = 1; ; ++tc) {
		cin >> N;

		if (!N) break;

		for (int y = 0; y < N; ++y) {
			for (int x = 0; x < N; ++x) {
				cin >> MAP[y][x];
				dist[y][x] = INF;
			}
		}

		priority_queue<Edge> pq;

		pq.push({ 0, 0, MAP[0][0] });
		dist[0][0] = MAP[0][0];

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

				int ncost = cost + MAP[ny][nx];

				if (dist[ny][nx] <= ncost)
					continue;

				pq.push({ ny, nx, ncost });
				dist[ny][nx] = ncost;
			}
		}

		cout << "Problem " << tc << ": " << dist[N - 1][N - 1] << '\n';
	}

	return 0;
}
