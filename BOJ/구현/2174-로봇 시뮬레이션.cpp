#include <iostream>
#include <vector>
#include <map>
#define sws ios::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

int dx[] = { 1, 0, -1, 0 };  // E, S, W, N
int dy[] = { 0, -1, 0, 1 };
map<char, int> direction = { {'E', 0}, {'S', 1}, {'W', 2}, {'N', 3} };
int N, M, robot_cnt, cmd_cnt;
int ground[102][102];

struct Robot {
	int y, x, dir;
};

vector<Robot> robots;

int oper(int robot_num, char cmd) {
	switch (cmd) {
	case 'L':
		robots[robot_num].dir = (robots[robot_num].dir - 1 + 4) % 4;
		break;
	case 'R':
		robots[robot_num].dir = (robots[robot_num].dir + 1) % 4;
		break;
	case 'F':
		int y = robots[robot_num].y, x = robots[robot_num].x, dir = robots[robot_num].dir;
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (ground[ny][nx] != 0)
			return ground[ny][nx];
		ground[ny][nx] = ground[y][x];
		ground[y][x] = 0;
		robots[robot_num].y = ny;
		robots[robot_num].x = nx;
		break;
	}
	return 0;
}

int main(void)
{
	sws;
	freopen("input.txt", "r", stdin);
	cin >> M >> N;
	cin >> robot_cnt >> cmd_cnt;
	for (int y = 0; y <= N + 1; y++)
		ground[y][0] = ground[y][M + 1] = -1;
	for (int x = 0; x <= M + 1; x++)
		ground[0][x] = ground[N + 1][x] = -1;
	robots.push_back(Robot{});
	for (int i = 0; i < robot_cnt; i++) {
		Robot robot = {};
		char d;
		cin >> robot.x >> robot.y >> d;
		robot.dir = direction[d];
		robots.push_back(robot);
		ground[robot.y][robot.x] = i + 1;
	}
	while (cmd_cnt--) {
		int robot_num, repeat_cnt;
		char cmd;
		cin >> robot_num >> cmd >> repeat_cnt;
		while (repeat_cnt--) {
			int result = oper(robot_num, cmd);
			if (result == -1) {
				cout << "Robot " << robot_num << " crashes into the wall\n";
				return 0;
			}
			if (result != 0) {
				cout << "Robot " << robot_num << " crashes into robot " << result << '\n';
				return 0;
			}
		}
	}
	cout << "OK\n";
	return 0;
}
