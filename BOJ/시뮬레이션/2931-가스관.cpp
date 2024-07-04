#include <iostream>
using namespace std;

constexpr int MAX_N = 25;
constexpr int MAX_M = 25;
constexpr int dx[]{ 0, 1, 0, -1, 0 };
constexpr int dy[]{ 0, 0, -1, 0, 1 };

constexpr int blocks[][5]{
	{0, 0, 0, 0, 0},
	{0, 0, 1, 4, 0},
	{0, 0, 0, 2, 1},
	{0, 2, 0, 0, 3},
	{0, 4, 3, 0, 0},
	{0, 0, 2, 0, 4},
	{0, 1, 0, 3, 0},
	{0, 1, 2, 3, 4}
};

constexpr char idx2char[]{ '.', '1', '2', '3', '4', '|', '-', '+' };

struct Pos {
	int y;
	int x;
};

int N, M, totalCnt;
int MAP[MAX_N][MAX_M];
Pos st, en, place;

void dfs(const int y, const int x, const int dir, const int cnt, const bool placed) {
	if (y == en.y && x == en.x) {
		if (cnt == totalCnt) cout << place.y + 1 << ' ' << place.x + 1 << ' ' << idx2char[MAP[place.y][place.x]] << '\n';
		return;
	}

	if (y < 0 || y >= N || x < 0 || x >= M) return;

	if (MAP[y][x]) {
		const int ndir = blocks[MAP[y][x]][dir];

		if (!ndir) return;

		const int ny = y + dy[ndir];
		const int nx = x + dx[ndir];

		dfs(ny, nx, ndir, cnt + 1, placed);
	}
	else if (!placed) {
		for (int idx = 1; idx <= 7; ++idx) {
			place = { y, x };
			MAP[y][x] = idx;

			const int ndir = blocks[MAP[y][x]][dir];

			if (!ndir) continue;

			const int ny = y + dy[ndir];
			const int nx = x + dx[ndir];

			dfs(ny, nx, ndir, cnt - (idx == 7), true);
		}

		MAP[y][x] = 0;
	}
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> M;

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			char ch;
			cin >> ch;

			if (ch == '.') continue;

			++totalCnt;

			if (ch == 'M') st = { y, x }, MAP[y][x] = 7;
			else if (ch == 'Z') en = { y, x };
			else if (ch == '1') MAP[y][x] = 1;
			else if (ch == '2') MAP[y][x] = 2;
			else if (ch == '3') MAP[y][x] = 3;
			else if (ch == '4') MAP[y][x] = 4;
			else if (ch == '|') MAP[y][x] = 5;
			else if (ch == '-') MAP[y][x] = 6;
			else if (ch == '+') MAP[y][x] = 7, ++totalCnt;
		}
	}

	for (int dir = 1; dir <= 4; ++dir)
		dfs(st.y, st.x, dir, 1, false);

	return 0;
}
