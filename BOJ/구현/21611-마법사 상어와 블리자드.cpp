#include <iostream>
#include <cstring>
using namespace std;

struct Pos {
	int y;
	int x;
};

constexpr int MAX_N = 49;
constexpr int dx[]{ 1, 0, -1, 0 };
constexpr int dy[]{ 0, -1, 0, 1 };
constexpr int input2dir[]{ 0, 1, 3, 2, 0 };

int N, M;
int MAP[MAX_N][MAX_N];
int temp[MAX_N][MAX_N];
Pos idx2pos[MAX_N * MAX_N];
int ans;

void move() {
	memset(temp, 0, sizeof(temp));

	int top = 1;

	for (int i = 1; i < N * N; ++i) {
		const auto& [y, x] = idx2pos[i];

		if (MAP[y][x]) {
			const auto& [ty, tx] = idx2pos[top++];
			temp[ty][tx] = MAP[y][x];
		}
	}

	memcpy(MAP, temp, sizeof(temp));
}

bool pop() {
	bool isPop = false;
	int prevIdx = 1;
	const auto& [py, px] = idx2pos[prevIdx];
	int prevType = MAP[py][px];

	for (int i = 1; i < N * N; ++i) {
		const auto& [y, x] = idx2pos[i];

		if (MAP[y][x] == prevType)
			continue;

		int cnt = i - prevIdx;

		if (cnt >= 4) {
			isPop = true;
			ans += prevType * cnt;

			for (int j = prevIdx; j < i; ++j) {
				const auto& [r, c] = idx2pos[j];
				MAP[r][c] = 0;
			}
		}

		if (MAP[y][x] == 0)
			break;

		prevIdx = i;
		prevType = MAP[y][x];
	}

	if (isPop)
		move();

	return isPop;
}

void change() {
	memset(temp, 0, sizeof(temp));

	int top = 1;
	int prevIdx = 1;
	const auto& [py, px] = idx2pos[prevIdx];
	int prevType = MAP[py][px];

	for (int i = 1; i < N * N; ++i) {
		const auto& [y, x] = idx2pos[i];

		if (MAP[y][x] == prevType)
			continue;

		int cnt = i - prevIdx;

		const auto& [fy, fx] = idx2pos[top++];
		temp[fy][fx] = cnt;

		const auto& [sy, sx] = idx2pos[top++];
		temp[sy][sx] = prevType;

		if (MAP[y][x] == 0)
			break;

		if (top >= N * N)
			break;

		prevIdx = i;
		prevType = MAP[y][x];
	}

	memcpy(MAP, temp, sizeof(temp));
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> M;

	const int MID = N / 2;

	int dir = 2;
	int y = MID;
	int x = MID;

	temp[y][x] = 1;
	idx2pos[0] = { y, x };

	for (int i = 1; i < N * N; ++i) {
		y += dy[dir];
		x += dx[dir];

		temp[y][x] = 1;
		idx2pos[i] = { y, x };

		int ndir = (dir + 1) % 4;
		int ny = y + dy[ndir];
		int nx = x + dx[ndir];

		if (!temp[ny][nx])
			dir = ndir;
	}

	for (int y = 0; y < N; ++y)
		for (int x = 0; x < N; ++x)
			cin >> MAP[y][x];

	for (int m = 0; m < M; ++m) {
		int dir, dist;
		cin >> dir >> dist;
		dir = input2dir[dir];

		int y = MID;
		int x = MID;

		for (int i = 0; i < dist; ++i) {
			y += dy[dir];
			x += dx[dir];
			MAP[y][x] = 0;
		}

		move();

		while (pop());

		change();
	}

	cout << ans << '\n';

	return 0;
}
