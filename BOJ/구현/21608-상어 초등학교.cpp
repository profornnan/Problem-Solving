#include <iostream>
#include <queue>
#define sws ios::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

struct Node {
	int likeCnt;
	int emptyCnt;
	int y;
	int x;
	bool operator<(Node next) const {
		if (likeCnt > next.likeCnt)
			return false;
		if (likeCnt < next.likeCnt)
			return true;
		if (emptyCnt > next.emptyCnt)
			return false;
		if (emptyCnt < next.emptyCnt)
			return true;
		if (y < next.y)
			return false;
		if (y > next.y)
			return true;
		if (x < next.x)
			return false;
		if (x > next.x)
			return true;
		return false;
	}
};

int dx[]{ 1, 0, -1, 0 };
int dy[]{ 0, -1, 0, 1 };

int score[]{ 0, 1, 10, 100, 1000 };

int N;
int MAP[20][20];
int favorite[401][401];

int main(void) {
	sws;
	cin >> N;
	for (int k = 0; k < N * N; k++) {
		int num;
		cin >> num;

		for (int i = 0; i < 4; i++) {
			int s;
			cin >> s;
			favorite[num][s] = 1;
		}

		priority_queue<Node> pq;

		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (MAP[y][x] != 0) continue;

				int likeCnt = 0, emptyCnt = 0;

				for (int i = 0; i < 4; i++) {
					int ny = y + dy[i];
					int nx = x + dx[i];

					if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;

					if (MAP[ny][nx] == 0)
						emptyCnt++;
					else if (favorite[num][MAP[ny][nx]] == 1)
						likeCnt++;
				}

				pq.push({ likeCnt, emptyCnt, y, x });
			}
		}

		Node now = pq.top();
		MAP[now.y][now.x] = num;
	}

	int ans = 0;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			int num = MAP[y][x];
			int likeCnt = 0;

			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;

				if (favorite[num][MAP[ny][nx]] == 1)
					likeCnt++;
			}

			ans += score[likeCnt];
		}
	}

	cout << ans << '\n';

	return 0;
}
