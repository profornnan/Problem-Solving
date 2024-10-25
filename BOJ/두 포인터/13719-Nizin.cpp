#include <iostream>
using namespace std;

constexpr int MAX_N = 1'000'000;

int N;
int arr[MAX_N];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	int ans = 0;
	int left = 0;
	int right = N - 1;
	long long leftSum = arr[left];
	long long rightSum = arr[right];

	while (left < right) {
		if (leftSum == rightSum) {
			leftSum = arr[++left];
			rightSum = arr[--right];
		}
		else if (leftSum < rightSum) {
			leftSum += arr[++left];
			++ans;
		}
		else if (leftSum > rightSum) {
			rightSum += arr[--right];
			++ans;
		}
	}

	cout << ans << '\n';

	return 0;
}
