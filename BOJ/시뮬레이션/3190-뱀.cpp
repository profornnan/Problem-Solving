#include <iostream>
#include <map>
#define sws ios::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

int dx[] = { 1, 0, -1, 0 };  // R, U, L, D
int dy[] = { 0, -1, 0, 1 };
int n, k, l;
int board[102][102];

struct Snake {
	int y, x, dir, time;
	Snake(int y, int x) {
		this->y = y, this->x = x, this->dir = 0, this->time = 0;
	}
};

int main(void)
{
	sws;
	freopen("input.txt", "r", stdin);
	cin >> n >> k;
	for (int i = 0; i <= n + 1; i++)
		board[0][i] = board[i][0] = board[n + 1][i] = board[i][n + 1] = 1;  // wall
	for (int i = 0; i < k; i++) {
		int r, c;
		cin >> r >> c;
		board[r][c] = 2;  // apple
	}
	cin >> l;
	map<int, char> rotation;  // time, dir('L' = left, 'D' = right)
	for (int i = 0; i < l; i++) {
		int t;
		char d;
		cin >> t >> d;
		rotation.insert({ t, d });
	}
	Snake head(1, 1), tail(1, 1);
	board[1][1] = 1;
	while (true) {
		head.y += dy[head.dir];
		head.x += dx[head.dir];
		head.time++;
		if (rotation.find(head.time) != rotation.end()) {
			if (rotation[head.time] == 'L')
				head.dir = (head.dir + 1) % 4;
			else if (rotation[head.time] == 'D')
				head.dir = (head.dir + 3) % 4;
		}
		if (board[head.y][head.x] == 1)
			break;
		else if (board[head.y][head.x] == 2)
			board[head.y][head.x] = 1;
		else if (board[head.y][head.x] == 0) {
			board[head.y][head.x] = 1;
			board[tail.y][tail.x] = 0;
			tail.y += dy[tail.dir];
			tail.x += dx[tail.dir];
			tail.time++;
			if (rotation.find(tail.time) != rotation.end()) {
				if (rotation[tail.time] == 'L')
					tail.dir = (tail.dir + 1) % 4;
				else if (rotation[tail.time] == 'D')
					tail.dir = (tail.dir + 3) % 4;
			}
		}
	}
	cout << head.time << '\n';
	return 0;
}
