#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

constexpr int dx[]{ 1, 0, -1, 0 };
constexpr int dy[]{ 0, -1, 0, 1 };

struct Virus {
	int id;
	int y;
	int x;

	bool operator<(const Virus& rhs) const {
		return id < rhs.id;
	}
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	vector<vector<int>> MAP(N, vector<int>(N));
	vector<Virus> virus;

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			cin >> MAP[y][x];

			if (MAP[y][x])
				virus.push_back({ MAP[y][x], y, x });
		}
	}

	sort(virus.begin(), virus.end());

	queue<Virus> q;

	for (const auto& v : virus)
		q.push(v);

	int S, Y, X;
	cin >> S >> Y >> X;

	int sec = 0;

	while (!q.empty() && sec < S) {
		int sz = q.size();
		++sec;

		while (sz--) {
			auto [id, y, x] = q.front();
			q.pop();

			for (int dir = 0; dir < 4; ++dir) {
				int ny = y + dy[dir];
				int nx = x + dx[dir];

				if (ny < 0 || ny >= N || nx < 0 || nx >= N)
					continue;

				if (MAP[ny][nx])
					continue;

				MAP[ny][nx] = id;
				q.push({ id, ny, nx });
			}
		}
	}

	cout << MAP[Y - 1][X - 1] << '\n';

	return 0;
}
