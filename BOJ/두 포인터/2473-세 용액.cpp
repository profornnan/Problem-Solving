#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> values(N);
	vector<int> ans(3);

	for (auto& val : values)
		cin >> val;

	sort(values.begin(), values.end());

	long long minSum = 2e18;

	for (int k = 0; k < N - 2; ++k) {
		int left = k + 1;
		int right = N - 1;

		while (left < right) {
			long long sum = static_cast<long long>(values[k]) + values[left] + values[right];

			if (abs(sum) < minSum) {
				minSum = abs(sum);
				ans = { values[k], values[left], values[right] };
			}

			sum < 0 ? ++left : --right;
		}
	}

	for (const auto& val : ans)
		cout << val << ' ';
	cout << '\n';

	return 0;
}
