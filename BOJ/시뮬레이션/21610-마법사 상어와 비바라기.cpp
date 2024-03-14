#include <iostream>
#include <queue>
using namespace std;

constexpr int MAX_N = 50;
constexpr int dx[]{ 0, -1, -1, 0, 1, 1, 1, 0, -1 };
constexpr int dy[]{ 0, 0, -1, -1, -1, 0, 1, 1, 1 };

int N, M;
int basket[MAX_N][MAX_N];
int temp[MAX_N][MAX_N];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> M;

	for (int y = 0; y < N; ++y)
		for (int x = 0; x < N; ++x)
			cin >> basket[y][x];

	queue<pair<int, int>> cloud({ {N - 1, 0}, {N - 1, 1}, {N - 2, 0}, {N - 2, 1} });

	while (M--) {
		int d, s;
		cin >> d >> s;

		int sz = cloud.size();

		while (sz--) {
			auto [y, x] = cloud.front();
			cloud.pop();

			y = (y + (N + dy[d]) * s) % N;
			x = (x + (N + dx[d]) * s) % N;

			++basket[y][x];
			cloud.push({ y, x });
		}

		while (!cloud.empty()) {
			auto [y, x] = cloud.front();
			cloud.pop();

			for (int i = 2; i <= 8; i += 2) {
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny < 0 || ny >= N || nx < 0 || nx >= N)
					continue;

				if (basket[ny][nx])
					++temp[y][x];
			}

			if (temp[y][x] == 0)
				temp[y][x] = -1;
		}

		for (int y = 0; y < N; ++y) {
			for (int x = 0; x < N; ++x) {
				if (temp[y][x] > 0)
					basket[y][x] += temp[y][x];

				if (basket[y][x] >= 2 && temp[y][x] == 0) {
					basket[y][x] -= 2;
					cloud.push({ y, x });
				}

				temp[y][x] = 0;
			}
		}
	}

	int ans = 0;

	for (int y = 0; y < N; ++y)
		for (int x = 0; x < N; ++x)
			ans += basket[y][x];

	cout << ans << '\n';

	return 0;
}
