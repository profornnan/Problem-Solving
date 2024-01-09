#include <iostream>
#include <cstring>
using namespace std;

constexpr int INF = 987654321;
constexpr int SIZE = 10;
constexpr int dx[]{ 1, 0, -1, 0 };
constexpr int dy[]{ 0, -1, 0, 1 };

bool initState[SIZE][SIZE];
bool bulb[SIZE][SIZE];
int ans = INF;

void toggle(int y, int x) {
	bulb[y][x] = !bulb[y][x];

	for (int dir = 0; dir < 4; ++dir) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if (ny < 0 || ny >= SIZE || nx < 0 || nx >= SIZE)
			continue;

		bulb[ny][nx] = !bulb[ny][nx];
	}
}

bool isBulbOn() {
	for (int x = 0; x < SIZE; ++x)
		if (bulb[SIZE - 1][x])
			return true;
	return false;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	for (int y = 0; y < SIZE; ++y) {
		for (int x = 0; x < SIZE; ++x) {
			char c;
			cin >> c;
			initState[y][x] = c == 'O' ? true : false;
		}
	}

	for (int mask = 0; mask < (1 << SIZE); ++mask) {
		int cnt{};
		memcpy(bulb, initState, sizeof(bulb));

		for (int x = 0; x < SIZE; ++x) {
			if (mask & (1 << x)) {
				toggle(0, x);
				++cnt;
			}
		}

		for (int y = 1; y < SIZE; ++y) {
			for (int x = 0; x < SIZE; ++x) {
				if (bulb[y - 1][x]) {
					toggle(y, x);
					++cnt;
				}
			}
		}

		if (!isBulbOn())
			ans = ans < cnt ? ans : cnt;
	}

	cout << (ans == INF ? -1 : ans) << '\n';

	return 0;
}
