#include <iostream>
#include <algorithm>
using namespace std;

constexpr int MAX_N = 100'000;

struct Cafe {
	int x;
	int y;
};

int T, N, M;
Cafe cafes[MAX_N + 1] = { { -1, 0 } };

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> T;

	while (T--) {
		cin >> N;

		for (int i = 1; i <= N; ++i)
			cin >> cafes[i].x >> cafes[i].y;

		sort(cafes + 1, cafes + N + 1, [](const Cafe& lhs, const Cafe& rhs) {
			return lhs.x != rhs.x ? lhs.x < rhs.x : lhs.y < rhs.y;
		});

		int idx = 1;

		while (idx <= N) {
			const int st = idx;

			while (idx <= N && cafes[st].x == cafes[idx].x)
				++idx;

			if (idx - st > 1 && cafes[st].y != cafes[st - 1].y) {
				sort(cafes + st, cafes + idx, [](const Cafe& lhs, const Cafe& rhs) {
					return lhs.x != rhs.x ? lhs.x < rhs.x : lhs.y > rhs.y;
				});
			}
		}

		cin >> M;

		while (M--) {
			int id;
			cin >> id;
			cout << cafes[id].x << ' ' << cafes[id].y << '\n';
		}
	}

	return 0;
}
