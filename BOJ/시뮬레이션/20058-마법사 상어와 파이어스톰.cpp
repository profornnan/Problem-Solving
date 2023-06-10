#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

struct Pos {
	int y;
	int x;
};

int dx[]{ 1, 0, -1, 0 };
int dy[]{ 0, -1, 0, 1 };

int N, Q, L;
int MAP_SIZE, ROT_SIZE;
int MAP[64][64];
int temp[64][64];

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> N >> Q;
	MAP_SIZE = (1 << N);

	for (int y = 0; y < MAP_SIZE; y++)
		for (int x = 0; x < MAP_SIZE; x++)
			cin >> MAP[y][x];

	while (Q--) {
		cin >> L;
		ROT_SIZE = (1 << L);

		for (int sy = 0; sy < MAP_SIZE; sy += ROT_SIZE)
			for (int sx = 0; sx < MAP_SIZE; sx += ROT_SIZE)
				for (int y = 0; y < ROT_SIZE; y++)
					for (int x = 0; x < ROT_SIZE; x++)
						temp[sy + x][sx + ROT_SIZE - 1 - y] = MAP[sy + y][sx + x];

		memcpy(MAP, temp, sizeof(MAP));

		vector<Pos> meltPos;

		for (int y = 0; y < MAP_SIZE; y++) {
			for (int x = 0; x < MAP_SIZE; x++) {
				if (MAP[y][x] == 0) continue;
				int iceCnt = 0;

				for (int dir = 0; dir < 4; dir++) {
					int ny = y + dy[dir];
					int nx = x + dx[dir];

					if (ny < 0 || ny >= MAP_SIZE || nx < 0 || nx >= MAP_SIZE) continue;
					if (MAP[ny][nx] > 0) iceCnt++;
				}

				if (iceCnt < 3) meltPos.push_back({ y, x });
			}
		}

		for (const Pos& pos : meltPos)
			MAP[pos.y][pos.x]--;
	}

	int sum = 0, maxCnt = 0;
	memset(temp, 0, sizeof(temp));

	for (int sy = 0; sy < MAP_SIZE; sy++) {
		for (int sx = 0; sx < MAP_SIZE; sx++) {
			if (MAP[sy][sx] == 0 || temp[sy][sx]) continue;

			int cnt = 0;

			queue<Pos> q;
			q.push({ sy, sx });
			temp[sy][sx] = 1;
			sum += MAP[sy][sx];
			cnt++;

			while (!q.empty()) {
				Pos now = q.front();
				q.pop();

				for (int dir = 0; dir < 4; dir++) {
					int ny = now.y + dy[dir];
					int nx = now.x + dx[dir];

					if (ny < 0 || ny >= MAP_SIZE || nx < 0 || nx >= MAP_SIZE) continue;
					if (MAP[ny][nx] == 0) continue;
					if (temp[ny][nx]) continue;

					q.push({ ny, nx });
					temp[ny][nx] = 1;
					sum += MAP[ny][nx];
					cnt++;
				}
			}

			maxCnt = maxCnt > cnt ? maxCnt : cnt;
		}
	}

	cout << sum << '\n' << maxCnt << '\n';

	return 0;
}
