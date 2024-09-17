#include <iostream>
#include <algorithm>
using namespace std;

constexpr int MAX_N = 5'000;
constexpr int MAX_A = 200'000;

int W, N;
int arr[MAX_N];
bool dp[MAX_A * 2 + 1];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> W >> N;

	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	sort(arr, arr + N);

	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			const int sub = W - (arr[i] + arr[j]);

			if (sub < 0)
				break;

			if (sub <= MAX_A * 2 && dp[sub]) {
				cout << "YES\n";
				return 0;
			}
		}

		for (int j = 0; j < i; ++j)
			dp[arr[i] + arr[j]] = true;
	}

	cout << "NO\n";

	return 0;
}
