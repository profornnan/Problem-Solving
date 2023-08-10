#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
using piii = tuple<int, int, int>;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, K, D;
	cin >> N >> K >> D;

	vector<piii> rules(K);

	for (auto& [st, en, interval] : rules)
		cin >> st >> en >> interval;

	int left = 1;
	int right = N;
	int ans = 0;

	while (left <= right) {
		int mid = left + (right - left) / 2;
		long long cnt = 0;

		for (const auto [st, en, interval] : rules) {
			if (mid < st) continue;
			cnt += (min(mid, en) - st) / interval + 1;
		}

		if (cnt >= D) {
			ans = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	cout << ans << '\n';

	return 0;
}
