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
};

struct Edge {
	Pos pos;
	int cost;

	bool operator<(const Edge& rhs) const {
		return cost > rhs.cost;
	}
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int T;
	cin >> T;

	while (T--) {
		int K, W, H;
		cin >> K >> W >> H;

		vector<int> char2cost('Z' - 'A' + 1);

		for (int i = 0; i < K; ++i) {
			char ch;
			int cost;

			cin >> ch >> cost;
			char2cost[ch - 'A'] = cost;
		}

		Pos st{};
		vector<vector<int>> MAP(H, vector<int>(W));

		for (int y = 0; y < H; ++y) {
			for (int x = 0; x < W; ++x) {
				char ch;
				cin >> ch;
				MAP[y][x] = char2cost[ch - 'A'];

				if (ch == 'E')
					st = { y, x };
			}
		}

		vector<vector<int>> dist(H, vector<int>(W, INF));
		priority_queue<Edge> pq;

		dist[st.y][st.x] = 0;
		pq.push({ st, 0 });

		while (!pq.empty()) {
			const auto [pos, cost] = pq.top();
			pq.pop();

			if (dist[pos.y][pos.x] < cost)
				continue;

			for (int dir = 0; dir < 4; ++dir) {
				int ny = pos.y + dy[dir];
				int nx = pos.x + dx[dir];

				if (ny < 0 || ny >= H || nx < 0 || nx >= W) {
					cout << cost << '\n';
					priority_queue<Edge>().swap(pq);
					break;
				}

				int ncost = cost + MAP[ny][nx];

				if (dist[ny][nx] <= ncost)
					continue;

				dist[ny][nx] = ncost;
				pq.push({ {ny, nx}, ncost });
			}
		}
	}

	return 0;
}
