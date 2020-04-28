#include <iostream>
#include <algorithm>
#include <cstring>
#define sws ios::sync_with_stdio(false), cin.tie(NULL);
using namespace std;

int board[40][40], sticker[10][10];
int n, m, k, r, c;

bool is_attachable(int sy, int sx) {
	if (sy + r > n || sx + c > m)
		return false;
	for (int y = 0; y < r; y++)
		for (int x = 0; x < c; x++)
			if (board[sy + y][sx + x] == 1 && sticker[y][x] == 1)
				return false;
	return true;
}

void attach(int sy, int sx) {
	for (int y = 0; y < r; y++)
		for (int x = 0; x < c; x++)
			if (sticker[y][x] == 1)
				board[sy + y][sx + x] = 1;
}

void rotate() {
	int temp[10][10];
	memset(temp, 0, sizeof(temp));
	for (int y = 0; y < r; y++)
		for (int x = 0; x < c; x++)
			temp[x][r - y - 1] = sticker[y][x];
	memcpy(sticker, temp, sizeof(sticker));
	swap(r, c);
}

void solve() {
	for (int i = 0; i < 4; i++) {
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < m; x++) {
				if (is_attachable(y, x)) {
					attach(y, x);
					return;
				}
			}
		}
		rotate();
	}
}

int main(void)
{
	sws;
	freopen("input.txt", "r", stdin);
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		cin >> r >> c;
		memset(sticker, 0, sizeof(sticker));
		for (int y = 0; y < r; y++)
			for (int x = 0; x < c; x++)
				cin >> sticker[y][x];
		solve();
	}
	int cnt = 0;
	for (int y = 0; y < n; y++)
		for (int x = 0; x < m; x++)
			if (board[y][x])
				cnt++;
	cout << cnt << '\n';
	return 0;
}
