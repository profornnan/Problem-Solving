#include <iostream>
#include <string>
#include <queue>
using namespace std;

enum {
	VISITED = 0,
	NOT_VISITED = 1,
	LAND_MINE = 2
};

int dx[]{ 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[]{ 0, -1, -1, -1, 0, 1, 1, 1 };

int N;
int MAP[300][300];

bool isZero(int y, int x) {
	for (int i = 0; i < 8; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
		if (MAP[ny][nx] == LAND_MINE) return false;
	}
	return true;
}

void click(int sy, int sx) {
	queue<pair<int, int>> q;
	q.push({ sy, sx });
	MAP[sy][sx] = VISITED;
	
	while (!q.empty()) {
		auto [y, x] = q.front();
		q.pop();
		for (int i = 0; i < 8; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= N || MAP[ny][nx] != NOT_VISITED) continue;
			if (isZero(ny, nx)) q.push({ ny, nx });
			MAP[ny][nx] = VISITED;
		}
	}
}

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int ans = 0;
		cin >> N;

		for (int y = 0; y < N; y++) {
			string str;
			cin >> str;
			for (int x = 0; x < N; x++)
				MAP[y][x] = str[x] == '*' ? LAND_MINE : NOT_VISITED;
		}

		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (MAP[y][x] != NOT_VISITED || !isZero(y, x)) continue;
				click(y, x);
				ans++;
			}
		}

		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++)
				if (MAP[y][x] == NOT_VISITED) ans++;

		cout << '#' << tc << ' ' << ans << '\n';
	}

	return 0;
}
