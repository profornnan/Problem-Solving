#include <iostream>
#include <algorithm>
#include <queue>
#define sws ios::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

struct Node {
	int y;
	int x;
	int range;
};

int dx[]{ 1, 0, -1, 0 };
int dy[]{ 0, -1, 0, 1 };

int N, H, W;
int MAP[15][12];
int totalCnt, ans;
queue<Node> q;

int simulation(int sx) {
	if (MAP[H - 1][sx] == 0) return 0;

	int cnt = 0;
	int sy = 0;

	while (MAP[sy][sx] == 0)
		sy++;

	q.push({ sy, sx, MAP[sy][sx] });
	MAP[sy][sx] = 0;
	cnt++;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int ny = now.y, nx = now.x;
			for (int i = 0; i < now.range - 1; i++) {
				ny += dy[dir];
				nx += dx[dir];

				if (ny < 0 || ny >= H || nx < 0 || nx >= W) break;
				if (MAP[ny][nx] == 0) continue;

				q.push({ ny, nx, MAP[ny][nx] });
				MAP[ny][nx] = 0;
				cnt++;
			}
		}
	}

	for (int x = 0; x < W; x++) {
		int idx = H - 1;

		for (int y = H - 1; y >= 0; y--)
			if (MAP[y][x] != 0)
				swap(MAP[y][x], MAP[idx--][x]);
	}

	return cnt;
}

void dfs(int level, int cnt) {
	ans = min(ans, totalCnt - cnt);
	
	if (level >= N)
		return;

	for (int sx = 0; sx < W; sx++) {
		if (MAP[H - 1][sx] == 0) continue;

		int COPY[15][12];

		for (int y = 0; y < H; y++)
			for (int x = 0; x < W; x++)
				COPY[y][x] = MAP[y][x];

		dfs(level + 1, cnt + simulation(sx));

		for (int y = 0; y < H; y++)
			for (int x = 0; x < W; x++)
				MAP[y][x] = COPY[y][x];
	}
}

int main(void) {
	sws;
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		totalCnt = 0;

		cin >> N >> W >> H;

		for (int y = 0; y < H; y++) {
			for (int x = 0; x < W; x++) {
				cin >> MAP[y][x];
				if (MAP[y][x] != 0)
					totalCnt++;
			}
		}

		ans = totalCnt;

		dfs(0, 0);

		cout << '#' << tc << ' ' << ans << '\n';
	}

	return 0;
}
