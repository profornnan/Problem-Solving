#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

const int dy[]{ 0, -1, 0, 1 };
const int dx[]{ 1, 0, -1, 0 };

const int jy[]{ -1, -2, -2, -1, 1, 2, 2, 1 };
const int jx[]{ 2, 1, -1, -2, -2, -1, 1, 2 };

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int K, W, H;
	cin >> K >> W >> H;

	vector<vector<int>> MAP(H, vector<int>(W));
	vector<vector<int>> visited(H, vector<int>(W, -1));

	for (auto& row : MAP)
		for (int& n : row)
			cin >> n;

	queue<tuple<int, int, int>> q;
	q.push({ 0, 0, K });
	visited[0][0] = K;
	int cnt = 0;

	while (!q.empty()) {
		int sz = q.size();

		while (sz--) {
			auto [y, x, k] = q.front();
			q.pop();

			if (y == H - 1 && x == W - 1) {
				cout << cnt << '\n';
				return 0;
			}

			for (int i = 0; i < 4; ++i) {
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
				if (MAP[ny][nx]) continue;
				if (visited[ny][nx] >= k) continue;

				q.push({ ny, nx, k });
				visited[ny][nx] = k;
			}

			if (!k) continue;

			for (int i = 0; i < 8; ++i) {
				int ny = y + jy[i];
				int nx = x + jx[i];

				if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
				if (MAP[ny][nx]) continue;
				if (visited[ny][nx] >= k - 1) continue;

				q.push({ ny, nx, k - 1 });
				visited[ny][nx] = k - 1;
			}
		}

		++cnt;
	}

	cout << "-1\n";

	return 0;
}
