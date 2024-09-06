#include <iostream>
#include <algorithm>
using namespace std;

constexpr int MAX_N = 100'000;

int N, K;
int arr[2];
int subs[MAX_N - 1];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> K;
	cin >> arr[0];

	for (int i = 1; i < N; ++i) {
		cin >> arr[i & 1];
		subs[i - 1] = arr[i & 1] - arr[(i - 1) & 1];
	}

	sort(subs, subs + N - 1);

	int ans = K;

	for (int i = 0; i < N - K; ++i)
		ans += subs[i];

	cout << ans << '\n';

	return 0;
}
