#include <iostream>
#include <algorithm>
using namespace std;

constexpr int MAX_N = 50;

int N, S;
int arr[MAX_N];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	cin >> S;

	for (int i = 0; i < N && S > 0; ++i) {
		const int maxIdx = max_element(arr + i, arr + min(N, i + S + 1)) - arr;

		for (int j = maxIdx; j > i; --j)
			swap(arr[j - 1], arr[j]);

		S -= maxIdx - i;
	}

	for (int i = 0; i < N; ++i)
		cout << arr[i] << ' ';
	cout << '\n';

	return 0;
}
