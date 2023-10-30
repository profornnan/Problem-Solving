#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
using pii = pair<int, int>;

constexpr int MAX_N = 20;
constexpr int MAX_M = 20;
constexpr int dx[]{ 1, 0, -1, 0 };
constexpr int dy[]{ 0, -1, 0, 1 };

int N, M, K;
int MAP[MAX_N][MAX_M];
bool visited[MAX_N][MAX_M];

struct Dice {
	int y, x, dir;
	int u, d, l, r, f, b;

	Dice() : y(0), x(0), dir(0), u(1), d(6), l(4), r(3), f(5), b(2) {}

	void move() {
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if (ny < 0 || ny >= N || nx < 0 || nx >= M) {
			dir = (dir + 2) % 4;
			ny = y + dy[dir];
			nx = x + dx[dir];
		}

		y = ny;
		x = nx;

		int temp = u;

		switch (dir) {
		case 0:  // E
			u = l;
			l = d;
			d = r;
			r = temp;
			break;
		case 1:  // N
			u = f;
			f = d;
			d = b;
			b = temp;
			break;
		case 2:  // W
			u = r;
			r = d;
			d = l;
			l = temp;
			break;
		case 3:  // S
			u = b;
			b = d;
			d = f;
			f = temp;
			break;
		}

		const int num = MAP[y][x];

		if (d > num)
			dir = (dir + 3) % 4;
		else if (d < num)
			dir = (dir + 1) % 4;
	}
};

int calcScore(int sy, int sx) {
	int cnt = 0;
	const int num = MAP[sy][sx];

	memset(visited, false, sizeof(visited));

	queue<pii> q;
	q.push({ sy, sx });
	visited[sy][sx] = true;

	while (!q.empty()) {
		const auto [y, x] = q.front();
		q.pop();

		++cnt;

		for (int dir = 0; dir < 4; ++dir) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue;

			if (visited[ny][nx])
				continue;

			if (MAP[ny][nx] != num)
				continue;

			q.push({ ny, nx });
			visited[ny][nx] = true;
		}
	}
	
	return cnt * num;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> M >> K;

	for (int y = 0; y < N; ++y)
		for (int x = 0; x < M; ++x)
			cin >> MAP[y][x];

	Dice dice;
	int totalScore = 0;

	for (int i = 0; i < K; ++i) {
		dice.move();
		totalScore += calcScore(dice.y, dice.x);
	}

	cout << totalScore << '\n';

	return 0;
}
