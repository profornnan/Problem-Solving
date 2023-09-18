#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using pii = pair<int, int>;

constexpr int INF = 987654321;

constexpr int dx[]{ 1, 0, -1, 0 };
constexpr int dy[]{ 0, -1, 0, 1 };

enum {
	EMPTY,
	WALL,
	JUMP
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, M, T;
	cin >> N >> M >> T;

	vector<vector<int>> MAP(N, vector<int>(M));
	vector<vector<int>> dist(N, vector<int>(M, INF));

	for (int y = 0; y < N; ++y)
		for (int x = 0; x < M; ++x)
			cin >> MAP[y][x];

	queue<pii> q;
	q.push({ 0, 0 });
	dist[0][0] = 0;

	while (!q.empty()) {
		auto [y, x] = q.front();
		q.pop();

		for (int dir = 0; dir < 4; ++dir) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue;

			if (MAP[ny][nx] == WALL)
				continue;

			if (dist[ny][nx] <= dist[y][x] + 1)
				continue;

			q.push({ ny, nx });
			dist[ny][nx] = dist[y][x] + 1;

			if (MAP[ny][nx] == JUMP)
				dist[N - 1][M - 1] = min(dist[N - 1][M - 1], dist[ny][nx] + (N - 1 - ny) + (M - 1 - nx));
		}
	}

	if (dist[N - 1][M - 1] <= T)
		cout << dist[N - 1][M - 1] << '\n';
	else
		cout << "Fail\n";

	return 0;
}
