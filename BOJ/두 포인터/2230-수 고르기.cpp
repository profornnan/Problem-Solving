#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

constexpr int INF = 21e8;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<int> arr(N);

	for (auto& num : arr)
		cin >> num;

	sort(arr.begin(), arr.end());

	int left = 0;
	int right = 0;
	int ans = INF;

	while (left < N && right < N) {
		const int diff = arr[right] - arr[left];

		if (diff >= M) {
			ans = min(ans, diff);
			++left;
		}
		else
			++right;
	}

	cout << ans << '\n';

	return 0;
}
