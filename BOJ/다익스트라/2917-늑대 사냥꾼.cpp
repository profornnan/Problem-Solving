#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

constexpr int MAX_N = 500;
constexpr int MAX_M = 500;
constexpr int dx[]{ 1, 0, -1, 0 };
constexpr int dy[]{ 0, -1, 0, 1 };

enum {
	EMPTY = '.',
	TREE = '+',
	START = 'V',
	END = 'J'
};

struct Pos {
	int y;
	int x;
};

struct Edge {
	Pos pos;
	int cost;

	bool operator<(const Edge& rhs) const {
		return cost < rhs.cost;
	}
};

int N, M;
int MAP[MAX_N][MAX_M];
int dist[MAX_N][MAX_M];
Pos st, en;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> M;

	queue<Pos> q;

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			char ch;
			cin >> ch;

			if (ch == TREE) {
				MAP[y][x] = 1;
				q.push({ y, x });
			}
			else if (ch == START)
				st = { y, x };
			else if (ch == END)
				en = { y, x };
		}
	}

	while (!q.empty()) {
		const auto [y, x] = q.front();
		q.pop();

		for (int dir = 0; dir < 4; ++dir) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue;

			if (MAP[ny][nx])
				continue;

			MAP[ny][nx] = MAP[y][x] + 1;
			q.push({ ny, nx });
		}
	}

	priority_queue<Edge> pq;

	dist[st.y][st.x] = MAP[st.y][st.x];
	pq.push({ st, MAP[st.y][st.x] });

	while (!pq.empty()) {
		const auto [y, x] = pq.top().pos;
		const auto cost = pq.top().cost;
		pq.pop();

		if (y == en.y && x == en.x) {
			cout << dist[y][x] - 1 << '\n';
			break;
		}

		if (dist[y][x] > cost)
			continue;

		for (int dir = 0; dir < 4; ++dir) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue;

			int ncost = min(cost, MAP[ny][nx]);

			if (dist[ny][nx] >= ncost)
				continue;

			dist[ny][nx] = ncost;
			pq.push({ { ny, nx }, ncost });
		}
	}

	return 0;
}
