#include <iostream>
#include <vector>
#include <map>
#include <set>
#define sws ios::sync_with_stdio(false), cin.tie(NULL);
using namespace std;

const int INF = 987654321;
int dx[] = { 0, 0, 0, -1, 1 };  // 1: U, 2: D, 3: L, 4: R
int dy[] = { 0, -1, 1, 0, 0 };
int N, M, K;
int shark_board[22][22];

struct Shark {
	int y, x, dir;
	vector<vector<int>> dir_priority;
	Shark() {
		y = 0, x = 0, dir = 0;
		dir_priority = vector<vector<int> >(5, vector<int>(5, 0));
	};
	Shark(int _y, int _x) {
		y = _y, x = _x;
		dir = 0;
		dir_priority = vector<vector<int> >(5, vector<int>(5, 0));
	}
};

struct Smell {
	int remain_time, shark_num;
	Smell() {
		remain_time = 0, shark_num = 0;
	}
	Smell(int _remain_time, int _shark_num) {
		remain_time = _remain_time, shark_num = _shark_num;
	}
};

map<int, Shark> sharks;
Smell smell_board[22][22];

void spread_smell() {
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			if (smell_board[y][x].shark_num != 0) {
				if (--smell_board[y][x].remain_time == 0) {
					smell_board[y][x].shark_num = 0;
				}
			}
		}
	}
	for (auto shark : sharks) {
		int y = shark.second.y, x = shark.second.x, shark_num = shark.first;
		smell_board[y][x].remain_time = K;
		smell_board[y][x].shark_num = shark_num;
	}
}

void move_shark(const int shark_num) {
	Shark &shark = sharks[shark_num];
	int y = shark.y, x = shark.x, dir = shark.dir;
	shark_board[y][x] = 0;
	vector<int> dir_priority = shark.dir_priority[dir];

	int ty = y, tx = x, t_dir = dir;

	for (int i = 1; i <= 4; i++) {
		int n_dir = dir_priority[i];
		int ny = y + dy[n_dir];
		int nx = x + dx[n_dir];

		if (smell_board[ny][nx].shark_num == 0) {
			shark.y = ny, shark.x = nx, shark.dir = n_dir;
			return;
		}
		if (smell_board[ny][nx].shark_num == shark_num) {
			if(ty == y && tx == x)
				ty = ny, tx = nx, t_dir = n_dir;
		}
	}
	shark.y = ty, shark.x = tx, shark.dir = t_dir;
}

void remove_shark() {
	set<pair<int, int> > visited;
	vector<int> deleted_shark_num;
	for (auto shark : sharks) {
		int y = shark.second.y, x = shark.second.x, shark_num = shark.first;
		if (visited.find(make_pair(y, x)) == visited.end()) {
			visited.insert(make_pair(y, x));
			shark_board[y][x] = shark.first;
		}
		else {
			deleted_shark_num.push_back(shark_num);
		}
	}
	for (int i = 0; i < deleted_shark_num.size(); i++)
		sharks.erase(deleted_shark_num[i]);
}

int simulation() {
	int cnt = 0;
	while (true) {
		if (cnt >= 1000)
			return -1;
		cnt++;
		for (auto shark : sharks)
			move_shark(shark.first);
		remove_shark();
		spread_smell();
		if (sharks.size() == 1)
			break;
	}
	return cnt;
}

int main(void)
{
	sws;
	freopen("input.txt", "r", stdin);
	cin >> N >> M >> K;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cin >> shark_board[y][x];
			if (shark_board[y][x] != 0) {
				sharks[shark_board[y][x]] = Shark(y, x);
				smell_board[y][x].shark_num = shark_board[y][x];
				smell_board[y][x].remain_time = K;
			}
		}
	}
	for (int y = 0; y <= N + 1; y++) {
		shark_board[y][0] = shark_board[y][N + 1] = -1;
		smell_board[y][0] = smell_board[y][N + 1] = Smell(INF, -1);
	}
	for (int x = 0; x <= N + 1; x++) {
		shark_board[0][x] = shark_board[N + 1][x] = -1;
		smell_board[0][x] = smell_board[N + 1][x] = Smell(INF, -1);
	}
	for (int i = 1; i <= sharks.size(); i++)
		cin >> sharks[i].dir;
	for (int i = 1; i <= sharks.size(); i++) {
		for (int j = 1; j <= 4; j++) {
			for (int k = 1; k <= 4; k++) {
				cin >> sharks[i].dir_priority[j][k];
			}
		}
	}

	cout << simulation() << '\n';

	return 0;
}
