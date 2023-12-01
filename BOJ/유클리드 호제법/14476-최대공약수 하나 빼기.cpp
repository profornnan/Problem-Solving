#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> nums(N + 2);

	for (int i = 1; i <= N; ++i)
		cin >> nums[i];

	vector<int> leftGCD(N + 2);
	vector<int> rightGCD(N + 2);

	leftGCD[1] = nums[1];
	rightGCD[N] = nums[N];

	for (int i = 2; i <= N; ++i)
		leftGCD[i] = gcd(leftGCD[i - 1], nums[i]);

	for (int i = N - 1; i >= 1; --i)
		rightGCD[i] = gcd(rightGCD[i + 1], nums[i]);

	int removedNum = 0;
	int maxGCD = 0;

	for (int i = 1; i <= N; ++i) {
		int GCD = gcd(leftGCD[i - 1], rightGCD[i + 1]);

		if (nums[i] % GCD != 0 && GCD > maxGCD) {
			removedNum = nums[i];
			maxGCD = GCD;
		}
	}

	if (removedNum == 0 && maxGCD == 0)
		cout << -1 << '\n';
	else
		cout << maxGCD << ' ' << removedNum << '\n';

	return 0;
}
