#include <iostream>
#include <queue>
using namespace std;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };
int r, c, n;
char board[200][200];
int time[200][200];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	cin >> r >> c >> n;
	queue<pair<int, int> > q;
	for (int y = 0; y < r; y++) {
		for (int x = 0; x < c; x++) {
			cin >> board[y][x];
			if (board[y][x] == 'O')
				q.push({ y, x });
		}
	}
	int sec = 1, pre_size = q.size();
	while (sec != n) {
		sec++;
		if (sec % 2 == 0) {		// ÆøÅº ¼³Ä¡
			pre_size = q.size();
			for (int y = 0; y < r; y++) {
				for (int x = 0; x < c; x++) {
					if (board[y][x] == '.') {
						board[y][x] = 'O';
						time[y][x] = sec;
						q.push({ y, x });
					}
				}
			}
		}
		else {					// Æø¹ß
			for (int k = 0; k < pre_size; k++) {
				int y = q.front().first;
				int x = q.front().second;
				q.pop();
				if (time[y][x] != sec - 3)
					continue;
				board[y][x] = '.';
				for (int i = 0; i < 4; i++) {
					int ny = y + dy[i];
					int nx = x + dx[i];
					if (0 <= ny && ny < r && 0 <= nx && nx < c) {
						board[ny][nx] = '.';
					}
				}
			}
		}
	}
	for (int y = 0; y < r; y++) {
		for (int x = 0; x < c; x++) {
			cout << board[y][x];
		}
		cout << '\n';
	}
	return 0;
}
