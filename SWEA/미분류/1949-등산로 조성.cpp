#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int dx[]{ 1, 0, -1, 0 };
int dy[]{ 0, -1, 0, 1 };

int N, K;
int MAP[8][8];
int visited[8][8];
int maxHeight;
int ans;

void dfs(int y, int x, int len, bool isCut) {

	visited[y][x] = 1;
	ans = max(ans, len);

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
		if (visited[ny][nx]) continue;

		if (MAP[ny][nx] < MAP[y][x])
			dfs(ny, nx, len + 1, isCut);
		else if (!isCut)
			for (int j = 1; j <= K; j++)
				if (MAP[ny][nx] - j < MAP[y][x]) {
					MAP[ny][nx] -= j;
					dfs(ny, nx, len + 1, true);
					MAP[ny][nx] += j;
				}
	}

	visited[y][x] = 0;
}

int main(void) {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cout << '#' << tc << ' ';

		ans = 0;
		maxHeight = 0;
		memset(visited, 0, sizeof(visited));

		cin >> N >> K;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				cin >> MAP[y][x];
				maxHeight = max(maxHeight, MAP[y][x]);
			}
		}

		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++)
				if (MAP[y][x] == maxHeight)
					dfs(y, x, 1, false);

		cout << ans << '\n';
	}

	return 0;
}
