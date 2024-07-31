#include <iostream>
#include <algorithm>
using namespace std;

constexpr int MAX_N = 1'000;

int N;
int arr[MAX_N];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	sort(arr, arr + N);

	for (int i = N - 1; i >= 0; --i) {
		for (int j = i - 1; j >= 0; --j) {
			int k = lower_bound(arr, arr + j, arr[i] - arr[j]) - arr;

			for (; k >= 0; k--) {
				if (binary_search(arr, arr + k + 1, arr[i] - arr[j] - arr[k])) {
					cout << arr[i] << '\n';
					return 0;
				}
			}
		}
	}

	return 0;
}
