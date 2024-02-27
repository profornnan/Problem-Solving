#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> nums(N);

	for (auto& num : nums)
		cin >> num;

	sort(nums.begin(), nums.end());

	int ans = 0;

	for (int i = 0; i < N; ++i) {
		const int target = nums[i];
		int left = 0;
		int right = N - 1;

		while (left < right) {
			const int sum = nums[left] + nums[right];
			if (sum == target) {
				if (left != i && right != i) {
					++ans;
					break;
				}
				else if (left == i) ++left;
				else if (right == i) --right;
			}
			else if (sum < target) ++left;
			else if (sum > target) --right;
		}
	}

	cout << ans << '\n';

	return 0;
}
