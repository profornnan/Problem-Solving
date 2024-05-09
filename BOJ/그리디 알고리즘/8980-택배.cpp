#include <iostream>
#include <algorithm>
using namespace std;

constexpr int MAX_N = 2'000;
constexpr int MAX_M = 10'000;

struct Box {
	int st;
	int en;
	int cnt;

	bool operator<(const Box& rhs) const {
		return st != rhs.st ? st < rhs.st : en < rhs.en;
	}
};

int N, C, M;
int ans, idx, capacity;
Box boxes[MAX_M];
int unloading[MAX_N + 1];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> C >> M;

	for (int i = 0; i < M; ++i)
		cin >> boxes[i].st >> boxes[i].en >> boxes[i].cnt;

	sort(boxes, boxes + M);

	for (int town = 1; town <= N; ++town) {
		capacity -= unloading[town];

		while (idx < M) {
			const auto& [st, en, cnt] = boxes[idx];

			if (st > town)
				break;

			++idx;

			const int loading = min(cnt, C - capacity);

			if (loading) {
				ans += loading;
				capacity += loading;
				unloading[en] += loading;
			}

			int remain = cnt - loading;

			for (int i = N; i > en; --i) {
				if (!remain)
					break;

				const int reloading = min(remain, unloading[i]);

				remain -= reloading;
				unloading[i] -= reloading;
				unloading[en] += reloading;
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
