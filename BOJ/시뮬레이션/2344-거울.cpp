#include <iostream>
using namespace std;

constexpr int MAX_N = 1'000;
constexpr int MAX_M = 1'000;
constexpr int dx[]{ 1, 0, -1, 0 };
constexpr int dy[]{ 0, -1, 0, 1 };
constexpr int reflect[]{ 1, 0, 3, 2 };

int N, M;
int MAP[MAX_N + 2][MAX_M + 2];

int shoot(int y, int x, int dir) {
	while (true) {
		if (MAP[y][x] == -1)
			dir = reflect[dir];

		y += dy[dir];
		x += dx[dir];

		if (y <= 0 || y > N || x <= 0 || x > M)
			break;
	}

	return MAP[y][x];
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> M;

	for (int y = 1; y <= N; ++y) {
		MAP[y][0] = y;
		MAP[y][M + 1] = 2 * N + M - y + 1;
	}

	for (int x = 1; x <= M; ++x) {
		MAP[N + 1][x] = N + x;
		MAP[0][x] = 2 * N + 2 * M - x + 1;
	}

	for (int y = 1; y <= N; ++y) {
		for (int x = 1; x <= M; ++x) {
			cin >> MAP[y][x];
			MAP[y][x] *= -1;
		}
	}

	for (int y = 1; y <= N; ++y)
		cout << shoot(y, 0, 0) << ' ';

	for (int x = 1; x <= M; ++x)
		cout << shoot(N + 1, x, 1) << ' ';

	for (int y = N; y >= 1; --y)
		cout << shoot(y, M + 1, 2) << ' ';

	for (int x = M; x >= 1; --x)
		cout << shoot(0, x, 3) << ' ';

	cout << '\n';

	return 0;
}
