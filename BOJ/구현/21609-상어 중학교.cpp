#include <iostream>
#include <algorithm>
#include <queue>
#define sws ios::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

enum {
	EMPTY = -2, BLACK = -1, RAINBOW = 0
};

struct Pos {
	int y;
	int x;
};

struct Group {
	int id;
	int blockCnt;
	int rainbowCnt;
	Pos pos;
};

bool cmp(Group left, Group right) {
	if (left.blockCnt > right.blockCnt)
		return true;
	if (left.blockCnt < right.blockCnt)
		return false;
	if (left.rainbowCnt > right.rainbowCnt)
		return true;
	if (left.rainbowCnt < right.rainbowCnt)
		return false;
	if (left.pos.y > right.pos.y)
		return true;
	if (left.pos.y < right.pos.y)
		return false;
	if (left.pos.x > right.pos.x)
		return true;
	if (left.pos.x < right.pos.x)
		return false;
	return false;
}

int dx[]{ 1, 0, -1, 0 };
int dy[]{ 0, -1, 0, 1 };

int N, M;
int MAP[20][20];
int ans;

bool deleteBlock() {
	vector<Group> groups;
	vector<vector<Pos>> blockPos(1);

	int visited[20][20]{};
	int id = 0;

	for (int sy = 0; sy < N; sy++) {
		for (int sx = 0; sx < N; sx++) {
			if (MAP[sy][sx] <= 0 || visited[sy][sx] != 0) continue;

			id++;
			blockPos.push_back({});

			int color = MAP[sy][sx], rainbowCnt = 0;

			queue<Pos> q;
			q.push({ sy, sx });

			visited[sy][sx] = id;

			while (!q.empty()) {
				Pos now = q.front();
				q.pop();

				blockPos[id].push_back({ now.y, now.x });

				if (MAP[now.y][now.x] == RAINBOW)
					rainbowCnt++;

				for (int i = 0; i < 4; i++) {
					int ny = now.y + dy[i];
					int nx = now.x + dx[i];

					if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
					if (visited[ny][nx] == id) continue;
					if (MAP[ny][nx] == BLACK || MAP[ny][nx] == EMPTY) continue;
					if (MAP[ny][nx] != RAINBOW && MAP[ny][nx] != color) continue;

					q.push({ ny, nx });
					visited[ny][nx] = id;
				}
			}

			if (blockPos[id].size() >= 2)
				groups.push_back({ id, (int)blockPos[id].size(), rainbowCnt, {sy, sx} });
		}
	}

	if (groups.empty())
		return false;

	sort(groups.begin(), groups.end(), cmp);

	Group target = groups[0];

	ans += target.blockCnt * target.blockCnt;

	for (Pos pos : blockPos[target.id])
		MAP[pos.y][pos.x] = EMPTY;

	return true;
}

void gravity() {
	for (int x = 0; x < N; x++) {
		int bottom = N - 1;

		for (int y = N - 1; y >= 0; y--) {
			if (MAP[y][x] == BLACK)
				bottom = y - 1;
			else if (MAP[y][x] != EMPTY)
				swap(MAP[bottom--][x], MAP[y][x]);
		}
	}
}

void rotateCCW() {
	int result[20][20]{};

	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			result[N - 1 - x][y] = MAP[y][x];

	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			MAP[y][x] = result[y][x];
}

void solve() {
	while (true) {
		if (!deleteBlock()) break;

		gravity();
		rotateCCW();
		gravity();
	}
}

int main(void) {
	sws;

	cin >> N >> M;

	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			cin >> MAP[y][x];

	solve();

	cout << ans << '\n';

	return 0;
}
