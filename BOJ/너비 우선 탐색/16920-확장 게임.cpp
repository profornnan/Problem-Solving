#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using pii = pair<int, int>;

constexpr int dx[]{ 1, 0, -1, 0 };
constexpr int dy[]{ 0, -1, 0, 1 };

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, M, P;
	cin >> N >> M >> P;

	vector<int> S(P);
	vector<int> cnt(P);
	vector<queue<pii>> vq(P);

	for (auto& s : S)
		cin >> s;

	vector<vector<char>> MAP(N, vector<char>(M));

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			cin >> MAP[y][x];

			if (MAP[y][x] == '.' || MAP[y][x] == '#')
				continue;

			int num = MAP[y][x] - '1';

			++cnt[num];
			vq[num].push({ y, x });
		}
	}

	while (true) {
		bool isAllEmpty = true;

		for (int i = 0; i < P; ++i) {
			for (int s = 0; s < S[i]; ++s) {
				int sz = vq[i].size();

				while (sz--) {
					const auto [y, x] = vq[i].front();
					vq[i].pop();

					for (int dir = 0; dir < 4; ++dir) {
						int ny = y + dy[dir];
						int nx = x + dx[dir];

						if (ny < 0 || ny >= N || nx < 0 || nx >= M)
							continue;

						if (MAP[ny][nx] != '.')
							continue;

						MAP[ny][nx] = i + '1';
						++cnt[i];
						vq[i].push({ ny, nx });
					}
				}

				if (vq[i].empty())
					break;
			}

			if (vq[i].size())
				isAllEmpty = false;
		}

		if (isAllEmpty)
			break;
	}

	for (const auto& c : cnt)
		cout << c << ' ';

	return 0;
}
