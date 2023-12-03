#include <iostream>
#include <string>
#include <cmath>
using namespace std;

constexpr int MAX_N = 9;
constexpr int MAX_M = 9;

int N, M;
int MAP[MAX_N][MAX_M];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> M;

	for (int y = 0; y < N; ++y) {
		string row;
		cin >> row;

		for (int x = 0; x < M; ++x)
			MAP[y][x] = row[x] - '0';
	}

	int ans = -1;

	for (int sy = 0; sy < N; ++sy) {
		for (int sx = 0; sx < M; ++sx) {
			for (int dy = -N; dy < N; ++dy) {
				for (int dx = -M; dx < M; ++dx) {
					if (dx == 0 && dy == 0)
						continue;

					int now = 0;
					int y = sy;
					int x = sx;

					while (true) {
						if (y < 0 || y >= N || x < 0 || x >= M)
							break;

						now *= 10;
						now += MAP[y][x];

						int root = static_cast<int>(sqrt(now));

						if (root * root == now && now > ans)
							ans = now;

						y += dy;
						x += dx;
					}
				}
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
