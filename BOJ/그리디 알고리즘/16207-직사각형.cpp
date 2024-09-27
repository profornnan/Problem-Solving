#include <iostream>
#include <algorithm>
using namespace std;

constexpr int MAX_N = 10'000;

int N;
int arr[MAX_N];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	sort(arr, arr + N);

	long long ans = 0;
	long long prev = 0;

	for (int i = N - 1; i > 0; --i) {
		if (arr[i] - arr[i - 1] > 1)
			continue;

		ans += prev * arr[i - 1];
		prev = prev ? 0 : arr[i - 1];
		--i;
	}

	cout << ans << '\n';

	return 0;
}
