#include <iostream>
#include <vector>
#include <cstring>
#define sws ios::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

const int BOARD_LEN = 4;
int dx[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };  // 1: ¡è, 2: ¢Ø, 3: ¡ç, 4: ¢×, 5: ¡é, 6: ¢Ù, 7: ¡æ, 8: ¢Ö
int dy[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };

struct Fish {
	int y, x, dir;
	bool is_deleted;
	Fish() {
		y = 0, x = 0, dir = 0;
		is_deleted = false;
	}
	Fish(int _y, int _x, int _dir) {
		y = _y, x = _x, dir = _dir;
		is_deleted = false;
	}
};

int board[6][6];
vector<Fish> fishes(17, Fish());
Fish shark = Fish(1, 1, 0);

int simulation() {
	int ret = 0;
	int deleted_fish_num = board[shark.y][shark.x];
	int temp_board[6][6];
	ret += deleted_fish_num;

	memcpy(temp_board, board, sizeof(board));
	vector<Fish> temp_fishes = fishes;
	Fish temp_shark = shark;
	board[shark.y][shark.x] = -1;
	fishes[deleted_fish_num].is_deleted = true;

	shark.dir = fishes[deleted_fish_num].dir;

	for (int fish_num = 1; fish_num < fishes.size(); fish_num++) {
		Fish fish = fishes[fish_num];

		if (fish.is_deleted)
			continue;

		int y = fish.y, x = fish.x, dir = fish.dir;

		for (int j = 0; j < 8; j++) {
			int n_dir = (dir + j + 7) % 8 + 1;
			int ny = y + dy[n_dir], nx = x + dx[n_dir];
			int n_fish_num = board[ny][nx];

			if (n_fish_num == 0) {
				fishes[fish_num].y = ny;
				fishes[fish_num].x = nx;
				fishes[fish_num].dir = n_dir;
				board[y][x] = 0;
				board[ny][nx] = fish_num;
				break;
			}

			else if (n_fish_num > 0 && n_fish_num <= 16) {
				fishes[fish_num].y = ny;
				fishes[fish_num].x = nx;
				fishes[fish_num].dir = n_dir;
				fishes[n_fish_num].y = y;
				fishes[n_fish_num].x = x;
				board[y][x] = n_fish_num;
				board[ny][nx] = fish_num;
				break;
			}
		}
	}
	
	board[shark.y][shark.x] = 0;

	int y = shark.y, x = shark.x, dir = shark.dir;
	int max_result = 0;

	while (true) {
		y += dy[dir];
		x += dx[dir];

		if (board[y][x] == -1)
			break;

		if (board[y][x] != 0) {
			shark.y = y, shark.x = x;
			int result = simulation();
			max_result = max_result > result ? max_result : result;
		}
	}

	memcpy(board, temp_board, sizeof(board));
	fishes = temp_fishes;
	shark = temp_shark;
	board[shark.y][shark.x] = deleted_fish_num;
	fishes[deleted_fish_num].is_deleted = false;

	ret += max_result;

	return ret;
}

int main(void) {
	sws;
	freopen("input.txt", "r", stdin);

	for (int y = 1; y <= BOARD_LEN; y++) {
		for (int x = 1; x <= BOARD_LEN; x++) {
			int fish_num, dir;
			cin >> fish_num >> dir;
			board[y][x] = fish_num;
			fishes[fish_num] = Fish(y, x, dir);
		}
	}

	for (int y = 0; y <= BOARD_LEN + 1; y++)
		board[y][0] = board[y][BOARD_LEN + 1] = -1;

	for (int x = 0; x <= BOARD_LEN + 1; x++)
		board[0][x] = board[BOARD_LEN + 1][x] = -1;

	cout << simulation() << '\n';

	return 0;
}
