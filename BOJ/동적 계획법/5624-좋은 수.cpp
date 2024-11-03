#include <iostream>
using namespace std;

constexpr int MAX_N = 5'000;
constexpr int MAX_A = 100'000;
constexpr int OFFSET = MAX_A * 2;

int N;
int arr[MAX_N];
bool dp[MAX_A * 4 + 1];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	int ans = 0;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < i; ++j) {
			if (dp[arr[i] - arr[j] + OFFSET]) {
				++ans;
				break;
			}
		}

		for (int j = 0; j <= i; ++j)
			dp[arr[i] + arr[j] + OFFSET] = true;
	}

	cout << ans << '\n';

	return 0;
}
