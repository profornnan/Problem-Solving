#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

constexpr long long INF = 2e18;
constexpr int dx[]{ 1, 0, -1, 0 };
constexpr int dy[]{ 0, -1, 0, 1 };

struct Pos {
	long long x;
	long long y;

	Pos(const long long x = 0, const long long y = 0) : x(x), y(y) {}

	bool operator<(const Pos& rhs) const {
		return x != rhs.x ? x < rhs.x : y < rhs.y;
	}

	Pos operator-(const Pos& rhs) const {
		return Pos(x - rhs.x, y - rhs.y);
	}

	long long dist() const {
		return abs(x) + abs(y);
	}
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	vector<Pos> items(N);

	for (auto& [x, y] : items)
		cin >> x >> y;

	Pos dest;
	cin >> dest.x >> dest.y;

	sort(items.begin(), items.end());

	long long ans = INF;

	// 0
	long long dist = dest.dist();

	if (dist <= K)
		ans = min(ans, dist);

	// 1
	if (2 <= K) {
		for (const auto& now : items) {
			dist = (dest - now).dist();

			if (dist + 2 <= K)
				ans = min(ans, dist + 2);
		}
	}

	// 2
	if (4 <= K && 4 < ans) {
		for (const auto& now : items) {
			if (binary_search(items.begin(), items.end(), dest - now)) {
				ans = min(ans, 4LL);
				break;
			}

			if (5 == K && 5 < ans) {
				for (int dir = 0; dir < 4; ++dir) {
					const Pos next = { now.x + dx[dir], now.y + dy[dir] };

					if (binary_search(items.begin(), items.end(), dest - next)) {
						ans = min(ans, 5LL);
						break;
					}
				}
			}
		}
	}

	cout << (ans == INF ? -1 : ans) << '\n';

	return 0;
}
