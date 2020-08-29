#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#define sws ios::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };
int N, M, max_height;
int board[52][52];
int ans = 0;

void bfs(int height) {
	queue<pair<int, int> > q;
	board[0][0] = height;
	q.push(make_pair(0, 0));
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= N + 2 || nx < 0 || nx >= M + 2)
				continue;
			if (board[ny][nx] < height) {
				board[ny][nx] = height;
				q.push(make_pair(ny, nx));
			}
		}
	}
}

int main(void)
{
	sws;
	freopen("input.txt", "r", stdin);
	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		string s;
		cin >> s;
		for (int x = 0; x < M; x++) {
			board[y + 1][x + 1] = s[x] - '0';
			max_height = max(max_height, board[y + 1][x + 1]);
		}
	}
	for (int h = 1; h <= max_height; h++) {
		bfs(h);
		for (int y = 1; y <= N; y++) {
			for (int x = 1; x <= M; x++) {
				if (board[y][x] < h) {
					board[y][x] = h;
					ans++;
				}
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
