#include <iostream>
#include <queue>
using namespace std;

constexpr int MAX_N = 1'000;
constexpr int dx[]{ 1, 0, -1, 0 };
constexpr int dy[]{ 0, -1, 0, 1 };

enum {
	EMPTY = '.',
	ICE = '#'
};

int N;
char MAP[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	for (int y = 0; y < N; ++y)
		for (int x = 0; x < N; ++x)
			cin >> MAP[y][x];

	int maxArea = 0;
	int minPerimeter = 0;

	for (int sy = 0; sy < N; ++sy) {
		for (int sx = 0; sx < N; ++sx) {
			if (MAP[sy][sx] == EMPTY || visited[sy][sx])
				continue;

			int area = 0;
			int perimeter = 0;
			queue<pair<int, int>> q;

			visited[sy][sx] = true;
			q.push({ sy, sx });

			while (!q.empty()) {
				const auto [y, x] = q.front();
				q.pop();

				++area;

				for (int dir = 0; dir < 4; ++dir) {
					const int ny = y + dy[dir];
					const int nx = x + dx[dir];

					if (ny < 0 || ny >= N || nx < 0 || nx >= N || MAP[ny][nx] == EMPTY) {
						++perimeter;
						continue;
					}

					if (visited[ny][nx])
						continue;

					visited[ny][nx] = true;
					q.push({ ny, nx });
				}
			}

			if (maxArea < area) {
				maxArea = area;
				minPerimeter = perimeter;
			}
			else if (maxArea == area)
				minPerimeter = minPerimeter < perimeter ? minPerimeter : perimeter;
		}
	}

	cout << maxArea << ' ' << minPerimeter << '\n';

	return 0;
}
