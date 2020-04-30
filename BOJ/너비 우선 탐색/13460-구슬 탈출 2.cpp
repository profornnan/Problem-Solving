#include <iostream>
#include <queue>
#define sws ios::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

struct Marble {
	int ry, rx, by, bx, depth;
};

int dx[] = { 1, 0, -1, 0 };  // R, U, L, D
int dy[] = { 0, -1, 0, 1 };
int n, m;
char board[10][10];
bool visited[10][10][10][10];  // ry, rx, by, bx

int move(int& y, int& x, int dir) {
	int cnt = 0;
	while (board[y + dy[dir]][x + dx[dir]] != '#' && board[y][x] != 'O') {
		y += dy[dir];
		x += dx[dir];
		cnt += 1;
	}
	return cnt;
}

int bfs(Marble marble) {
	queue<Marble> q;
	q.push(marble);
	visited[marble.ry][marble.rx][marble.by][marble.bx] = true;
	while (!q.empty()) {
		int ry = q.front().ry, rx = q.front().rx;
		int by = q.front().by, bx = q.front().bx;
		int depth = q.front().depth;
		q.pop();
		if (depth >= 10) break;
		for (int dir = 0; dir < 4; dir++) {
			int n_ry = ry, n_rx = rx, n_by = by, n_bx = bx;
			int n_depth = depth + 1;
			int r_cnt = move(n_ry, n_rx, dir);
			int b_cnt = move(n_by, n_bx, dir);
			if (board[n_by][n_bx] == 'O')
				continue;
			if (board[n_ry][n_rx] == 'O')
				return n_depth;
			if (n_ry == n_by && n_rx == n_bx) {
				if (r_cnt > b_cnt)
					n_ry -= dy[dir], n_rx -= dx[dir];
				else
					n_by -= dy[dir], n_bx -= dx[dir];
			}
			if (!visited[n_ry][n_rx][n_by][n_bx]) {
				visited[n_ry][n_rx][n_by][n_bx] = true;
				q.push({ n_ry, n_rx, n_by, n_bx, n_depth });
			}
		}
	}
	return -1;
}

int main(void)
{
	sws;
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	Marble marble{};
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			cin >> board[y][x];
			if (board[y][x] == 'R')
				marble.ry = y, marble.rx = x;
			else if (board[y][x] == 'B')
				marble.by = y, marble.bx = x;
		}
	}
	cout << bfs(marble) << '\n';
	return 0;
}
