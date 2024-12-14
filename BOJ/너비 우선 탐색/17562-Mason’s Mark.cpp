#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

constexpr int MAX_H = 1'000;
constexpr int MAX_W = 1'000;
constexpr int dx[]{ 1, 1, 0, -1, -1, -1, 0, 1 };
constexpr int dy[]{ 0, -1, -1, -1, 0, 1, 1, 1 };

enum {
	BLACK = '#',
	WHITE = '.'
};

int H, W;
char MAP[MAX_H][MAX_W];
bool visited[MAX_H][MAX_W];
int A, B, C;

bool isNoise(const int y, const int x) {
	if (MAP[y][x] == WHITE)
		return false;

	for (int dir = 0; dir < 8; ++dir) {
		const int ny = y + dy[dir];
		const int nx = x + dx[dir];

		if (ny < 0 || ny >= H || nx < 0 || nx >= W)
			continue;

		if (MAP[ny][nx] == BLACK)
			return false;
	}

	return true;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> W >> H;

	for (int y = 0; y < H; ++y)
		for (int x = 0; x < W; ++x)
			cin >> MAP[y][x];

	for (int y = 0; y < H; ++y)
		for (int x = 0; x < W; ++x)
			if (isNoise(y, x))
				MAP[y][x] = WHITE;

	for (int sy = 0; sy < H; ++sy) {
		for (int sx = 0; sx < W; ++sx) {
			if (MAP[sy][sx] == WHITE || visited[sy][sx])
				continue;

			int ey = sy;
			int ex = sx;

			queue<pair<int, int>> q;

			q.push({ sy, sx });
			visited[sy][sx] = true;

			while (!q.empty()) {
				const auto [y, x] = q.front();
				q.pop();

				ey = max(ey, y);
				ex = max(ex, x);

				for (int dir = 0; dir < 8; ++dir) {
					const int ny = y + dy[dir];
					const int nx = x + dx[dir];

					if (ny < 0 || ny >= H || nx < 0 || nx >= W)
						continue;

					if (MAP[ny][nx] == WHITE)
						continue;

					if (visited[ny][nx])
						continue;

					q.push({ ny, nx });
					visited[ny][nx] = true;
				}
			}

			if (sy == 0 && sx == 0)
				continue;

			const int my = (sy + ey) / 2;
			const int mx = (sx + ex) / 2;

			if (MAP[ey][mx] == WHITE)
				++A;
			else if (MAP[my][ex] == WHITE)
				++C;
			else
				++B;
		}
	}

	cout << A << ' ' << B << ' ' << C << '\n';

	return 0;
}
