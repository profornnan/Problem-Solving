#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> arr(N);

	for (auto& num : arr)
		cin >> num;

	sort(arr.begin(), arr.end());

	int ans = 0;

	do {
		int sum = 0;
		int left = 0;
		int right = 0;
		int cnt = 0;

		while (left < N) {
			if (sum == 50) {
				sum += arr[right % N] - arr[left % N];
				++right;
				++left;
				++cnt;
			}
			else if (sum < 50) {
				sum += arr[right % N];
				++right;
			}
			else {
				sum -= arr[left % N];
				++left;
			}
		}

		ans = max(ans, cnt);
	} while (next_permutation(arr.begin(), arr.end()));

	cout << ans / 2 << '\n';

	return 0;
}
