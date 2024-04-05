#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

constexpr int MAX_N = 100;
constexpr int MAX_K = 100;
constexpr int dx[]{ 1, 0, -1, 0 };
constexpr int dy[]{ 0, -1, 0, 1 };

struct Pos {
	int y;
	int x;
};

int N, K, R;
Pos cow[MAX_K + 1];
bool road[MAX_N + 1][MAX_N + 1][4];
bool visited[MAX_N + 1][MAX_N + 1];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> K >> R;

	for (int i = 0; i < R; ++i) {
		Pos a, b;
		cin >> a.y >> a.x >> b.y >> b.x;

		for (int dir = 0; dir < 4; ++dir) {
			int ny = a.y + dy[dir];
			int nx = a.x + dx[dir];

			if (ny == b.y && nx == b.x) {
				road[a.y][a.x][dir] = road[b.y][b.x][(dir + 2) % 4] = true;
				break;
			}
		}
	}

	for (int i = 0; i < K; ++i)
		cin >> cow[i].y >> cow[i].x;

	int ans = 0;

	for (int i = 0; i < K; ++i) {
		const Pos st = cow[i];

		queue<Pos> q;
		memset(visited, 0, sizeof(visited));

		q.push(st);
		visited[st.y][st.x] = true;

		while (!q.empty()) {
			const auto [y, x] = q.front();
			q.pop();

			for (int dir = 0; dir < 4; ++dir) {
				int ny = y + dy[dir];
				int nx = x + dx[dir];

				if (ny <= 0 || ny > N || nx <= 0 || nx > N)
					continue;

				if (visited[ny][nx])
					continue;

				if (road[y][x][dir])
					continue;

				q.push({ ny, nx });
				visited[ny][nx] = true;
			}
		}

		for (int j = i + 1; j < K; ++j) {
			const Pos en = cow[j];

			if (!visited[en.y][en.x])
				++ans;
		}
	}

	cout << ans << '\n';

	return 0;
}
