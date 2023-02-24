#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Node {
	int y;
	int x;
	Node(int y, int x) : y(y), x(x) {}
	bool operator==(Node next) {
		return y == next.y && x == next.x;
	}
};

int dx[]{ 1, 0, -1, 0 };  // R U L D
int dy[]{ 0, -1, 0, 1 };

int N;
int MAP[102][102];
vector<vector<Node>> wormhole;
int ans;

int blockDir[6][4]{
	{0, 0, 0, 0},
	{2, 3, 1, 0},
	{2, 0, 3, 1},
	{3, 2, 0, 1},
	{1, 3, 0, 2},
	{2, 3, 0, 1}
};

void simulation(int sy, int sx, int sdir) {
	MAP[sy][sx] = -1;

	int score = 0;
	int y = sy, x = sx, dir = sdir;

	while (true) {
		y += dy[dir];
		x += dx[dir];

		if (MAP[y][x] == -1) break;

		int block = MAP[y][x];

		if (block >= 1 && block <= 5) {
			dir = blockDir[block][dir];
			score++;
		}
		else if (block >= 6 && block <= 10) {
			Node next = Node(y, x) == wormhole[block][0] ? wormhole[block][1] : wormhole[block][0];

			y = next.y;
			x = next.x;
		}
	}

	MAP[sy][sx] = 0;

	ans = max(ans, score);
}

int main(void) {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		ans = 0;
		wormhole = vector<vector<Node>>(11);

		cin >> N;
		for (int i = 0; i <= N + 1; i++)
			MAP[0][i] = MAP[N + 1][i] = MAP[i][0] = MAP[i][N + 1] = 5;

		for (int y = 1; y <= N; y++) {
			for (int x = 1; x <= N; x++) {
				cin >> MAP[y][x];
				if (MAP[y][x] >= 6 && MAP[y][x] <= 10)
					wormhole[MAP[y][x]].push_back({ y, x });
			}
		}

		for (int y = 1; y <= N; y++)
			for (int x = 1; x <= N; x++)
				if (MAP[y][x] == 0)
					for (int i = 0; i < 4; i++)
						simulation(y, x, i);

		cout << '#' << tc << ' ' << ans << '\n';
	}

	return 0;
}
