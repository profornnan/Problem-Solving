#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

constexpr int MAX_N = 300'000;

int N, K;
int height[MAX_N];
int diff[MAX_N - 1];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> K;

	cin >> height[0];

	for (int i = 1; i < N; ++i) {
		cin >> height[i];
		diff[i - 1] = height[i] - height[i - 1];
	}

	sort(diff, diff + N - 1);

	cout << accumulate(diff, diff + N - K, 0) << '\n';

	return 0;
}
