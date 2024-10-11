#include <iostream>
using namespace std;

constexpr long long INF = 2e18;
constexpr int M = 3;

int N;
int player[M];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < M; ++i)
		cin >> player[i];

	long long left = 1;
	long long right = INF;
	long long ans = 0;

	while (left <= right) {
		const long long mid = left + (right - left) / 2;
		long long cnt = 0;

		for (int i = 0; i < M; ++i)
			cnt += mid / player[i];

		if (cnt >= N) {
			ans = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	long long cnt = 0;

	for (int i = 0; i < M; ++i)
		cnt += (ans - 1) / player[i];

	for (int i = 0; i < M; ++i) {
		cnt += !(ans % player[i]);

		if (cnt == N) {
			cout << static_cast<char>('A' + i) << " win\n";
			break;
		}
	}

	return 0;
}
