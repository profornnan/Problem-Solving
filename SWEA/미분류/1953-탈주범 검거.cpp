#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

struct Node {
	int y;
	int x;
};

int dx[]{ 1, 0, -1, 0 };  // R U L D
int dy[]{ 0, -1, 0, 1 };

int pipe[8][4]{
	{0, 0, 0, 0},
	{1, 1, 1, 1},
	{0, 1, 0, 1},
	{1, 0, 1, 0},
	{1, 1, 0, 0},
	{1, 0, 0, 1},
	{0, 0, 1, 1},
	{0, 1, 1, 0}
};

int N, M, R, C, L;
int MAP[50][50];
int visited[50][50];

int bfs() {
	queue<Node> q;
	q.push({ R, C });

	memset(visited, 0, sizeof(visited));
	visited[R][C] = 1;

	int cnt = 0;
	int hour = 0;

	while (!q.empty()) {

		int sz = q.size();

		hour++;

		while (sz--) {
			Node now = q.front();
			q.pop();

			cnt++;
			int p = MAP[now.y][now.x];

			for (int i = 0; i < 4; i++) {
				if (pipe[p][i] == 0) continue;

				int ny = now.y + dy[i];
				int nx = now.x + dx[i];

				if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
				if (visited[ny][nx] != 0) continue;
				if (pipe[MAP[ny][nx]][(i + 2) % 4] == 0) continue;

				visited[ny][nx] = 1;
				q.push({ ny, nx });
			}
		}

		if (hour == L)
			break;
	}

	return cnt;
}

int main(void) {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cout << '#' << tc << ' ';
		cin >> N >> M >> R >> C >> L;

		for (int y = 0; y < N; y++)
			for (int x = 0; x < M; x++)
				cin >> MAP[y][x];

		cout << bfs() << '\n';
	}

	return 0;
}
