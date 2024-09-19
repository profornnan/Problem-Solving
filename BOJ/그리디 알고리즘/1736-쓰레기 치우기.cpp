#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Pos {
	int y;
	int x;

	bool operator<(const Pos& rhs) const {
		return y != rhs.y ? y < rhs.y : x < rhs.x;
	}
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<Pos> trash;

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			int exist;
			cin >> exist;

			if (exist)
				trash.push_back({ y, x });
		}
	}

	sort(trash.begin(), trash.end());

	vector<bool> visited(trash.size());

	int cnt = 0;
	int ans = 0;

	while (cnt < trash.size()) {
		int y = 0;
		int x = 0;

		for (int i = 0; i < trash.size(); ++i) {
			if (visited[i])
				continue;

			const auto& [ny, nx] = trash[i];

			if (y <= ny && x <= nx) {
				y = ny;
				x = nx;
				visited[i] = true;
				++cnt;
			}
		}

		++ans;
	}

	cout << ans << '\n';

	return 0;
}
