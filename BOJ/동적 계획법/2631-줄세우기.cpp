#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> arr(N);
	vector<int> dp(N, 1);

	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < i; ++j)
			if (arr[j] < arr[i])
				dp[i] = max(dp[i], dp[j] + 1);

	cout << N - *max_element(dp.begin(), dp.end()) << '\n';

	return 0;
}
