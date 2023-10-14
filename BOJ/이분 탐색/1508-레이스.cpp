#include <iostream>
#include <vector>
using namespace std;

constexpr int INF = 987654321;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, M, K;
	cin >> N >> M >> K;

	vector<int> pos(K);

	for (auto& p : pos)
		cin >> p;

	int left = 0;
	int right = pos[K - 1] - pos[0];
	int res = -1;

	while (left <= right) {
		int mid = left + (right - left) / 2;
		int prev = -INF;
		int cnt = 0;

		for (const auto& p : pos) {
			if (p - prev < mid)
				continue;

			prev = p;
			++cnt;
		}

		if (cnt >= M) {
			res = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}

	int prev = -INF;
	int cnt = 0;

	for (const auto& p : pos) {
		if (p - prev >= res && cnt < M) {
			++cnt;
			prev = p;
			cout << 1;
		}
		else
			cout << 0;
	}

	cout << '\n';

	return 0;
}
