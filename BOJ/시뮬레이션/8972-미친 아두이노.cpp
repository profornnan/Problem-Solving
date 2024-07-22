#include <iostream>
#include <string>
using namespace std;

constexpr int MAX_R = 100;
constexpr int MAX_C = 100;
constexpr int dx[]{ 0, -1, 0, 1, -1, 0, 1, -1, 0, 1 };
constexpr int dy[]{ 0, 1, 1, 1, 0, 0, 0, -1, -1, -1 };

struct Pos {
	int y;
	int x;
};

inline int getSign(const int num) {
	return (num > 0) - (num < 0);
}

int R, C, A;
char MAP[MAX_R][MAX_C];
int visited[MAX_R][MAX_C];
Pos player;
Pos arduinos[MAX_R * MAX_C];
bool alives[MAX_R * MAX_C];
string cmds;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> R >> C;

	for (int y = 0; y < R; ++y) {
		for (int x = 0; x < C; ++x) {
			cin >> MAP[y][x];

			if (MAP[y][x] == 'I')
				player = { y, x };
			else if (MAP[y][x] == 'R') {
				arduinos[A] = { y, x };
				alives[A] = true;
				++A;
			}
		}
	}

	cin >> cmds;

	for (int cnt = 1; cnt <= cmds.size(); ++cnt) {
		const int dir = cmds[cnt - 1] - '0';

		MAP[player.y][player.x] = '.';

		player.y += dy[dir];
		player.x += dx[dir];

		if (MAP[player.y][player.x] == 'R') {
			cout << "kraj " << cnt << '\n';
			return 0;
		}

		MAP[player.y][player.x] = 'I';

		for (int id = 0; id < A; ++id) {
			if (!alives[id])
				continue;

			auto& [y, x] = arduinos[id];

			MAP[y][x] = '.';

			y += getSign(player.y - y);
			x += getSign(player.x - x);

			if (y == player.y && x == player.x) {
				cout << "kraj " << cnt << '\n';
				return 0;
			}

			if (visited[y][x] / A == cnt) {
				alives[id] = alives[visited[y][x] % A] = false;
				continue;
			}

			visited[y][x] = cnt * A + id;
		}

		for (int id = 0; id < A; ++id)
			if (alives[id])
				MAP[arduinos[id].y][arduinos[id].x] = 'R';
	}

	for (int y = 0; y < R; ++y) {
		for (int x = 0; x < C; ++x)
			cout << MAP[y][x];
		cout << '\n';
	}

	return 0;
}
