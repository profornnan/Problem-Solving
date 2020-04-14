#include <iostream>
#define sws ios::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

int dx[] = { 1, -1, 0, 0 };  // µ¿ = 0, ¼­ = 1, ºÏ = 2, ³² = 3
int dy[] = { 0, 0, -1, 1 };
int n, m;
int board[20][20];

struct Dice {
	int y, x;
	int u, d, l, r, f, b;
	void move_dice(int dir) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (0 <= ny && ny < n && 0 <= nx && nx < m) {
			y = ny, x = nx;
			if (dir == 0) {			// µ¿
				int temp = u;
				u = l;
				l = d;
				d = r;
				r = temp;
			}
			else if (dir == 1) {	// ¼­
				int temp = u;
				u = r;
				r = d;
				d = l;
				l = temp;
			}
			else if (dir == 2) {	// ºÏ
				int temp = u;
				u = f;
				f = d;
				d = b;
				b = temp;
			}
			else if (dir == 3) {	// ³²
				int temp = u;
				u = b;
				b = d;
				d = f;
				f = temp;
			}
			if (board[y][x] == 0) {
				board[y][x] = d;
			}
			else {
				d = board[y][x];
				board[y][x] = 0;
			}
			cout << u << '\n';
		}
	}
};

int main(void)
{
	sws;
	freopen("input.txt", "r", stdin);
	Dice dice = {};
	int oper, k;
	cin >> n >> m >> dice.y >> dice.x >> k;
	for (int y = 0; y < n; y++)
		for (int x = 0; x < m; x++)
			cin >> board[y][x];
	while (k--) {
		cin >> oper;
		dice.move_dice(oper - 1);
	}
	return 0;
}
