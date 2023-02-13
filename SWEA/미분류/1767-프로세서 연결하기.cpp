#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

struct Node {
	int y;
	int x;
};

int dx[]{ 1, 0, -1, 0 };
int dy[]{ 0, -1, 0, 1 };

int N;
int MAP[14][14];
vector<Node> v;
int max_core, min_wire;

void dfs(int level, int core, int wire) {
	if (level >= v.size()) {
		if (max_core < core) {
			max_core = core;
			min_wire = wire;
		}
		else if (max_core == core) {
			min_wire = min_wire < wire ? min_wire : wire;
		}
		return;
	}

	dfs(level + 1, core, wire);

	Node now = v[level];

	for (int i = 0; i < 4; i++) {
		int ny = now.y + dy[i];
		int nx = now.x + dx[i];
		int cnt = 0;

		while (MAP[ny][nx] == 0) {
			MAP[ny][nx] = 2;
			ny += dy[i];
			nx += dx[i];
			cnt++;
		}

		if (MAP[ny][nx] == -1)
			dfs(level + 1, core + 1, wire + cnt);

		ny = now.y + dy[i];
		nx = now.x + dx[i];

		for (int j = 0; j < cnt; j++) {
			MAP[ny][nx] = 0;
			ny += dy[i];
			nx += dx[i];
		}
	}
}

int main(void) {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cout << '#' << tc << ' ';

		v = vector<Node>();
		max_core = 0, min_wire = 0;
		memset(MAP, -1, sizeof(MAP));

		cin >> N;
		
		for (int y = 1; y <= N; y++) {
			for (int x = 1; x <= N; x++) {
				cin >> MAP[y][x];
				if (MAP[y][x] == 1 && y != 1 && y != N && x != 1 && x != N)
					v.push_back({ y, x });
			}
		}

		dfs(0, 0, 0);

		cout << min_wire << '\n';
	}

	return 0;
}
