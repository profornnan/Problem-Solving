#include <iostream>
#include <algorithm>
#define sws ios::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

int N, M;
int arr[5000];

bool isValid(int target) {
	int nMax = arr[0], nMin = arr[0];
	int cnt = 1;

	for (int i = 1; i < N; i++) {
		nMax = max(nMax, arr[i]);
		nMin = min(nMin, arr[i]);

		if (nMax - nMin > target) {
			nMax = nMin = arr[i];
			cnt++;
		}
	}

	if (cnt <= M)
		return true;

	return false;
}

int psearch() {
	int left = 0;
	int right = 10000;
	int ans = 0;

	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (isValid(mid)) {
			ans = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	return ans;
}

int main(void) {
	sws;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	cout << psearch() << '\n';

	return 0;
}
