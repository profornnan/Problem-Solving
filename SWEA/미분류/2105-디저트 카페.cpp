#include <iostream>
#include <algorithm>
using namespace std;

int dx[] = { 1, -1, -1, 1 };  // RD LD LU RU
int dy[] = { 1, 1, -1, -1 };

int T, N;
int dessert[20][20];
int cnt, max_cnt, sy, sx;
int visited[101];

void dfs(int y, int x, int dir) {
	if (y == sy && x == sx && dir == 3) {
		max_cnt = max(max_cnt, cnt);
		return;
	}

	for (int i = 0; i < 2; i++) {
		int ndir = dir + i;

		if (dir > 3)
			continue;

		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if (ny < 0 || ny >= N || nx < 0 || nx >= N)
			continue;

		if (visited[dessert[ny][nx]] == 1)
			continue;

		cnt++;
		visited[dessert[ny][nx]] = 1;

		dfs(ny, nx, ndir);

		visited[dessert[ny][nx]] = 0;
		cnt--;
	}
}

int main(void) {
	cin >> T;

	for (int t = 0; t < T; t++) {
		cout << '#' << t + 1 << ' ';

		cin >> N;

		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++)
				cin >> dessert[y][x];

		max_cnt = -1;

		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				sy = y, sx = x;
				dfs(y, x, 0);
			}
		}

		cout << max_cnt << '\n';
	}

	return 0;
}
