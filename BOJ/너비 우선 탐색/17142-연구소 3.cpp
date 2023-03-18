#include <iostream>
#include <vector>
#include <queue>
#define sws ios::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

struct Node {
	int y;
	int x;
};

enum {
	EMPTY = 0, WALL = 1, VIRUS = 2
};

int dx[]{ 1, 0, -1, 0 };
int dy[]{ 0, -1, 0, 1 };

const int INF = 987654321;
int N, M;
int MAP[52][52];
vector<Node> virus;
int selected[10];
int ans = INF, emptyCnt;

void bfs() {
	int hour = 0, spreadCnt = 0;
	int visited[52][52]{};
	queue<Node> q;

	for (int i = 0; i < M; i++) {
		Node v = virus[selected[i]];
		q.push(v);
		visited[v.y][v.x] = 1;
	}

	while (!q.empty()) {
		if (spreadCnt == emptyCnt) {
			ans = ans < hour ? ans : hour;
			return;
		}

		hour++;

		if (hour >= ans)
			return;

		int sz = q.size();

		while (sz--) {
			Node now = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				int ny = now.y + dy[i];
				int nx = now.x + dx[i];

				if (MAP[ny][nx] == WALL) continue;
				if (visited[ny][nx] != 0) continue;
				
				if (MAP[ny][nx] == EMPTY)
					spreadCnt++;

				q.push({ ny, nx });
				visited[ny][nx] = 1;
			}
		}
	}
}

void dfs(int level, int last) {
	if (level >= M) {
		bfs();
		return;
	}

	for (int i = last + 1; i < virus.size(); i++) {
		selected[level] = i;
		dfs(level + 1, i);
		selected[level] = 0;
	}
}

int main(void) {
	sws;

	cin >> N >> M;

	for (int i = 0; i <= N + 1; i++)
		MAP[0][i] = MAP[N + 1][i] = MAP[i][0] = MAP[i][N + 1] = WALL;

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cin >> MAP[y][x];
			if (MAP[y][x] == VIRUS)
				virus.push_back({ y, x });
			if (MAP[y][x] == EMPTY)
				emptyCnt++;
		}
	}

	dfs(0, -1);

	if (ans == INF)
		ans = -1;

	cout << ans << '\n';

	return 0;
}
