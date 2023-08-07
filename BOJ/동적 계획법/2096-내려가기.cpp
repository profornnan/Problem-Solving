#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 21e8;
const int dx[]{ -1, 0, 1 };

int minDp[2][3];
int maxDp[2][3];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		int y = i & 1;
		int ny = !y;

		minDp[ny][0] = minDp[ny][1] = minDp[ny][2] = INF;

		for (int x = 0; x < 3; ++x) {
			int num;
			cin >> num;

			for (int dir = 0; dir < 3; ++dir) {
				int nx = x + dx[dir];

				if (nx < 0 || nx >= 3) continue;

				minDp[ny][nx] = min(minDp[ny][nx], minDp[y][x] + num);
				maxDp[ny][nx] = max(maxDp[ny][nx], maxDp[y][x] + num);
			}
		}
	}

	int y = N & 1;

	cout << max({ maxDp[y][0], maxDp[y][1], maxDp[y][2] }) << ' ' << min({ minDp[y][0], minDp[y][1], minDp[y][2] }) << '\n';

	return 0;
}
