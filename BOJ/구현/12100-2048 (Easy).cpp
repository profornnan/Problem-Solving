#include <iostream>
#include <deque>
#define sws ios::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

int n, max_block;
int board[20][20];

void shift(int dir) {
	deque<int> dq;
	switch (dir) {
	case 0:  // L
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				if (board[y][x] != 0) {
					dq.push_back(board[y][x]);
					board[y][x] = 0;
				}
			}
			int index = 0;
			while (!dq.empty()) {
				if (dq.size() == 1) {
					board[y][index] = dq.front();
					dq.pop_front();
				}
				else if (dq[0] == dq[1]) {
					board[y][index] = 2 * dq[0];
					dq.pop_front();
					dq.pop_front();
				}
				else {
					board[y][index] = dq[0];
					dq.pop_front();
				}
				index++;
			}
		}
		break;
	case 1:  // R
		for (int y = 0; y < n; y++) {
			for (int x = n - 1; x >= 0; x--) {
				if (board[y][x] != 0) {
					dq.push_back(board[y][x]);
					board[y][x] = 0;
				}
			}
			int index = n - 1;
			while (!dq.empty()) {
				if (dq.size() == 1) {
					board[y][index] = dq.front();
					dq.pop_front();
				}
				else if (dq[0] == dq[1]) {
					board[y][index] = 2 * dq[0];
					dq.pop_front();
					dq.pop_front();
				}
				else {
					board[y][index] = dq[0];
					dq.pop_front();
				}
				index--;
			}
		}
		break;
	case 2:  // U
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < n; y++) {
				if (board[y][x] != 0) {
					dq.push_back(board[y][x]);
					board[y][x] = 0;
				}
			}
			int index = 0;
			while (!dq.empty()) {
				if (dq.size() == 1) {
					board[index][x] = dq.front();
					dq.pop_front();
				}
				else if (dq[0] == dq[1]) {
					board[index][x] = 2 * dq[0];
					dq.pop_front();
					dq.pop_front();
				}
				else {
					board[index][x] = dq[0];
					dq.pop_front();
				}
				index++;
			}
		}
		break;
	case 3:  // D
		for (int x = 0; x < n; x++) {
			for (int y = n - 1; y >= 0; y--) {
				if (board[y][x] != 0) {
					dq.push_back(board[y][x]);
					board[y][x] = 0;
				}
			}
			int index = n - 1;
			while (!dq.empty()) {
				if (dq.size() == 1) {
					board[index][x] = dq.front();
					dq.pop_front();
				}
				else if (dq[0] == dq[1]) {
					board[index][x] = 2 * dq[0];
					dq.pop_front();
					dq.pop_front();
				}
				else {
					board[index][x] = dq[0];
					dq.pop_front();
				}
				index--;
			}
		}
		break;
	}
}

void dfs(int cnt) {
	if (cnt == 5) {
		for (int y = 0; y < n; y++)
			for (int x = 0; x < n; x++)
				max_block = max_block > board[y][x] ? max_block : board[y][x];
		return;
	}
	int temp[20][20];
	for (int y = 0; y < n; y++)
		for (int x = 0; x < n; x++)
			temp[y][x] = board[y][x];
	for (int i = 0; i < 4; i++) {
		shift(i);
		dfs(cnt + 1);
		for (int y = 0; y < n; y++)
			for (int x = 0; x < n; x++)
				board[y][x] = temp[y][x];
	}
}

int main(void)
{
	sws;
	freopen("input.txt", "r", stdin);
	cin >> n;
	for (int y = 0; y < n; y++)
		for (int x = 0; x < n; x++)
			cin >> board[y][x];
	dfs(0);
	cout << max_block << '\n';
	return 0;
}
