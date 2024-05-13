#include <iostream>
#include <queue>
using namespace std;

constexpr int INF = 987654321;
constexpr int MAX_N = 1'000;
constexpr int MAX_M = 1'000;
constexpr int MAX_K = 10;
constexpr int dx[]{ 1, 0, -1, 0 };
constexpr int dy[]{ 0, -1, 0, 1 };

struct Node {
	int y;
	int x;
	int cnt;
	int cost;
};

int N, M, K;
bool wall[MAX_N][MAX_M];
int visited[MAX_N][MAX_M];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> M >> K;

	for (int y = 0; y < N; ++y) {
		string row;
		cin >> row;

		for (int x = 0; x < M; ++x) {
			wall[y][x] = row[x] == '1';
			visited[y][x] = INF;
		}
	}

	queue<Node> q;

	visited[0][0] = 0;
	q.push({ 0, 0, 0, 1 });

	while (!q.empty()) {
		auto [y, x, cnt, cost] = q.front();
		q.pop();

		if (y == N - 1 && x == M - 1) {
			cout << cost << '\n';
			return 0;
		}

		for (int dir = 0; dir < 4; ++dir) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue;

			if (wall[ny][nx]) {
				if (cnt >= K)
					continue;

				if (cost & 1) {
					if (visited[ny][nx] <= cnt + 1)
						continue;

					visited[ny][nx] = cnt + 1;
					q.push({ ny, nx, cnt + 1, cost + 1 });
				}
				else {
					q.push({ y, x, cnt, cost + 1 });
				}
			}
			else {
				if (visited[ny][nx] <= cnt)
					continue;

				visited[ny][nx] = cnt;
				q.push({ ny, nx, cnt, cost + 1 });
			}
		}
	}

	cout << "-1\n";

	return 0;
}
