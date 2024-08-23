#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

constexpr int INF = 21e8;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	vector<int> arr(N);

	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	int ans = -INF;
	int res = 0;

	for (int i = 1; i < N; ++i) {
		res = arr[i] - arr[i - 1] - K + max(res, 0);
		ans = max(ans, res);
	}

	res = 0;

	for (int i = 1; i < N; ++i) {
		res = arr[i - 1] - arr[i] - K + max(res, 0);
		ans = max(ans, res);
	}

	cout << ans << '\n';

	return 0;
}
