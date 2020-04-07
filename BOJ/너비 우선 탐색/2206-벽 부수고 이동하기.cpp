#include <iostream>
#include <queue>
#define sws ios::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };
int n, m;
char board[1000][1000];
int dist[1000][1000][2];		// y, x, is_broken

int bfs() {
	queue<pair<pair<int, int>, int> > q;		// y, x, is_broken
	q.push({ {0, 0}, 0 });
	dist[0][0][0] = 1;
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int is_broken = q.front().second;
		q.pop();
		if (y == n - 1 && x == m - 1)
			return dist[y][x][is_broken];
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (0 <= ny && ny < n && 0 <= nx && nx < m) {
				if (board[ny][nx] == '0' && dist[ny][nx][is_broken] == 0) {
					q.push({ {ny, nx}, is_broken });
					dist[ny][nx][is_broken] = dist[y][x][is_broken] + 1;
				}
				if (board[ny][nx] == '1' && is_broken == 0) {
					q.push({ {ny, nx}, 1 });
					dist[ny][nx][1] = dist[y][x][0] + 1;
				}
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
	for (int y = 0; y < n; y++)
		for (int x = 0; x < m; x++)
			cin >> board[y][x];
	cout << bfs() << '\n';
	return 0;
}
