#include <iostream>
#include <queue>
#define sws ios::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };
int r, c, wolf_cnt, sheep_cnt;
char board[250][250];
bool visited[250][250];

int main(void)
{
	sws;
	freopen("input.txt", "r", stdin);
	cin >> r >> c;
	for (int y = 0; y < r; y++)
		for (int x = 0; x < c; x++)
			cin >> board[y][x];
	for (int sy = 0; sy < r; sy++) {
		for (int sx = 0; sx < c; sx++) {
			if (board[sy][sx] != '.' && board[sy][sx] != '#' && !visited[sy][sx]) {
				queue<pair<int, int> > q;
				int v_cnt = 0, k_cnt = 0;
				visited[sy][sx] = true;
				q.push({ sy, sx });
				while (!q.empty()) {
					int y = q.front().first;
					int x = q.front().second;
					q.pop();
					if (board[y][x] == 'v')
						v_cnt++;
					if (board[y][x] == 'k')
						k_cnt++;
					for (int i = 0; i < 4; i++) {
						int ny = y + dy[i];
						int nx = x + dx[i];
						if (0 <= ny && ny < r && 0 <= nx && nx < c) {
							if (board[ny][nx] != '#' && !visited[ny][nx]) {
								visited[ny][nx] = true;
								q.push({ ny, nx });
							}
						}
					}
				}
				if (v_cnt < k_cnt)
					sheep_cnt += k_cnt;
				else
					wolf_cnt += v_cnt;
			}
		}
	}
	cout << sheep_cnt << ' ' << wolf_cnt << '\n';
	return 0;
}
