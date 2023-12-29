#include <iostream>
#include <string>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int K;
	cin >> K;

	string ans{};
	int left{}, right{};
	int n = 2;

	while (right < K) {
		left = right;
		right += n;
		n *= 2;
	}

	++left;

	while (left < right) {
		int mid = left + (right - left) / 2;

		if (K <= mid) {
			ans.push_back('4');
			right = mid;
		}
		else {
			ans.push_back('7');
			left = mid + 1;
		}
	}

	cout << ans << '\n';

	return 0;
}
