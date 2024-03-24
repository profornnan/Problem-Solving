#include <iostream>
#include <vector>
#include <queue>
using namespace std;

constexpr int INF = 987654321;
constexpr int dx[]{ 1, 0, -1, 0 };
constexpr int dy[]{ 0, -1, 0, 1 };

struct Pos {
	int y;
	int x;

	bool operator==(const Pos& rhs) const {
		return y == rhs.y && x == rhs.x;
	}
};

struct Cost {
	int pass;
	int near;

	bool operator<(const Cost& rhs) const {
		return pass != rhs.pass ? pass < rhs.pass : near < rhs.near;
	}

	bool operator==(const Cost& rhs) const {
		return pass == rhs.pass && near == rhs.near;
	}

	Cost operator+(const Cost& rhs) const {
		return { pass + rhs.pass, near + rhs.near };
	}
};

struct Edge {
	Pos pos;
	Cost cost;

	bool operator<(const Edge& rhs) const {
		return rhs.cost < cost;
	}
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	Pos st, en;
	vector<string> forest(N);

	for (auto& row : forest)
		cin >> row;

	vector<vector<Cost>> MAP(N, vector<Cost>(M));

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			const char ch = forest[y][x];
			auto& [pass, near] = MAP[y][x];

			if (ch == 'S')
				st = { y, x };
			else if (ch == 'F')
				en = { y, x };
			else if (ch == 'g')
				++pass;
			else if (ch == '.') {
				for (int dir = 0; dir < 4; ++dir) {
					int ny = y + dy[dir];
					int nx = x + dx[dir];

					if (ny < 0 || ny >= N || nx < 0 || nx >= M)
						continue;

					if (forest[ny][nx] == 'g') {
						++near;
						break;
					}
				}
			}
		}
	}

	vector<vector<Cost>> dist(N, vector<Cost>(M, { INF, INF }));
	priority_queue<Edge> pq;

	dist[st.y][st.x] = { 0, 0 };
	pq.push({ st, { 0, 0 } });

	while (!pq.empty()) {
		const auto [pos, cost] = pq.top();
		pq.pop();

		if (pos == en) {
			const auto [pass, near] = dist[pos.y][pos.x];
			cout << pass << ' ' << near << '\n';
			return 0;
		}

		if (dist[pos.y][pos.x] < cost)
			continue;

		for (int dir = 0; dir < 4; ++dir) {
			int ny = pos.y + dy[dir];
			int nx = pos.x + dx[dir];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue;

			Cost ncost = cost + MAP[ny][nx];

			if (dist[ny][nx] < ncost || dist[ny][nx] == ncost)
				continue;

			dist[ny][nx] = ncost;
			pq.push({ { ny, nx }, ncost });
		}
	}

	return 0;
}
