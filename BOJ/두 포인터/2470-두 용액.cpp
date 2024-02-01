#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> nums(N);

	for (auto& num : nums)
		cin >> num;

	sort(nums.begin(), nums.end());

	int left = 0;
	int right = N - 1;

	int leftNum = nums[left];
	int rightNum = nums[right];
	int minSum = leftNum + rightNum;

	while (left < right) {
		int sum = nums[left] + nums[right];

		if (abs(sum) < abs(minSum)) {
			minSum = sum;
			leftNum = nums[left];
			rightNum = nums[right];
		}

		sum < 0 ? ++left : --right;
	}

	cout << leftNum << ' ' << rightNum << '\n';

	return 0;
}
