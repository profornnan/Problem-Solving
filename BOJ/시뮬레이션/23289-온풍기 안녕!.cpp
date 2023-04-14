#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

struct Node {
	int y;
	int x;
	int dir;
};

int dx[]{ 1, 0, -1, 0 };
int dy[]{ 0, -1, 0, 1 };

int dirx[5][3]{
	{0, 0, 0},
	{1, 1, 1},
	{-1, -1, -1},
	{-1, 0, 1},
	{-1, 0, 1}
};  // X, R, L, U, D
int diry[5][3]{
	{0, 0, 0},
	{-1, 0, 1},
	{-1, 0, 1},
	{-1, -1, -1},
	{1, 1, 1}
};  // X, R, L, U, D

int R, C, K, W;
int MAP[20][20];
int wall[20][20][20][20];  // y1, x1, y2, x2
int tempInc[20][20];
int visited[20][20];
vector<Node> heater;
vector<Node> survey;

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> R >> C >> K;

	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			cin >> MAP[y][x];
			if (MAP[y][x] == 0) continue;
			if (MAP[y][x] == 5)
				survey.push_back({ y, x, 0 });
			else
				heater.push_back({ y, x, MAP[y][x] });
			MAP[y][x] = 0;
		}
	}

	cin >> W;

	for (int i = 1; i <= W; i++) {
		int y, x, t;
		cin >> y >> x >> t;
		y--, x--;
		if (t == 0)
			wall[y][x][y - 1][x] = wall[y - 1][x][y][x] = 1;
		else if (t == 1)
			wall[y][x][y][x + 1] = wall[y][x + 1][y][x] = 1;
	}

	for (int k = 0; k < heater.size(); k++) {
		Node heat = heater[k];
		queue<Node> q;
		memset(visited, 0, sizeof(visited));

		int sy = heat.y + diry[heat.dir][1];
		int sx = heat.x + dirx[heat.dir][1];
		
		q.push({ sy, sx, heat.dir });
		visited[sy][sx] = 5;
		tempInc[sy][sx] += visited[sy][sx];

		while (!q.empty()) {
			Node now = q.front();
			q.pop();

			for (int i = 0; i < 3; i++) {
				int ny = now.y + diry[now.dir][i];
				int nx = now.x + dirx[now.dir][i];

				if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
				if (visited[ny][nx] != 0) continue;

				if (now.dir == 1 || now.dir == 2) {
					if (wall[now.y][now.x][ny][now.x] || wall[ny][now.x][ny][nx])
						continue;
				}
				else if (now.dir == 3 || now.dir == 4) {
					if (wall[now.y][now.x][now.y][nx] || wall[now.y][nx][ny][nx])
						continue;
				}

				visited[ny][nx] = visited[now.y][now.x] - 1;
				tempInc[ny][nx] += visited[ny][nx];
				
				if (visited[ny][nx] == 1) continue;

				q.push({ ny, nx, now.dir });
			}
		}
	}

	int ans = 0;

	while (true) {
		// 온풍기 동작
		for (int y = 0; y < R; y++)
			for (int x = 0; x < C; x++)
				MAP[y][x] += tempInc[y][x];

		// 온도 조절
		memset(visited, 0, sizeof(visited));

		for (int y = 0; y < R; y++) {
			for (int x = 0; x < C; x++) {
				for (int i = 0; i < 4; i++) {
					int ny = y + dy[i];
					int nx = x + dx[i];

					if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
					if (wall[y][x][ny][nx]) continue;
					if (MAP[y][x] <= MAP[ny][nx]) continue;

					int diff = MAP[y][x] - MAP[ny][nx];

					visited[y][x] -= diff / 4;
					visited[ny][nx] += diff / 4;
				}
			}
		}

		for (int y = 0; y < R; y++)
			for (int x = 0; x < C; x++)
				MAP[y][x] += visited[y][x];

		// 바깥쪽 온도 1 감소
		for (int y = 0; y < R; y++) {
			if (MAP[y][0] > 0) MAP[y][0]--;
			if (MAP[y][C - 1] > 0) MAP[y][C - 1]--;
		}

		for (int x = 1; x < C - 1; x++) {
			if (MAP[0][x] > 0) MAP[0][x]--;
			if (MAP[R - 1][x] > 0) MAP[R - 1][x]--;
		}

		// 초콜릿 먹기
		ans++;

		if (ans > 100)
			break;

		// 검사
		int cnt = 0;

		for (Node node : survey)
			if (MAP[node.y][node.x] >= K)
				cnt++;

		if (cnt == survey.size())
			break;
	}

	cout << ans << '\n';

	return 0;
}
