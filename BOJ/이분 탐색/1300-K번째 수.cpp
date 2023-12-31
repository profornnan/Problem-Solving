#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	int left = 1;
	int right = K;
	int ans = 0;

	while (left <= right) {
		int mid = left + (right - left) / 2;
		int cnt = 0;

		for (int i = 1; i <= N; ++i)
			cnt += min(mid / i, N);

		if (cnt >= K) {
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
