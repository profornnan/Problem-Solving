#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	const int S = static_cast<long long>(N) * (N - 1) / 2;
	vector<int> arr(N);

	for (auto& num : arr)
		cin >> num;

	sort(arr.begin(), arr.end());

	int left = arr[0] + arr[1];
	int right = arr[N - 2] + arr[N - 1];
	int ans = 0;

	while (left <= right) {
		const int mid = left + (right - left) / 2;
		long long cnt = 0;

		for (const auto& num : arr) {
			if (num >= mid)
				break;

			cnt += upper_bound(arr.begin(), arr.end(), mid - num) - arr.begin() - (num <= mid - num);
		}

		if (cnt / 2 >= (S + 1) / 2) {
			right = mid - 1;
			ans = mid;
		}
		else
			left = mid + 1;
	}

	cout << ans << '\n';

	return 0;
}
