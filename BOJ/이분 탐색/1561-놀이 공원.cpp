#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<int> T(M);

	for (auto& t : T)
		cin >> t;

	if (N <= M) {
		cout << N << '\n';
		return 0;
	}

	long long left = 0;
	long long right = T[0] * static_cast<long long>(N);
	long long minute = right;

	while (left <= right) {
		long long mid = left + (right - left) / 2;
		long long cnt = 0;

		for (const auto& t : T)
			cnt += mid / t + 1;

		if (cnt >= N) {
			minute = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	int cnt = 0;

	for (const auto& t : T)
		cnt += (minute - 1) / t + 1;

	for (int i = 0; i < M; ++i) {
		if (minute % T[i] == 0 && ++cnt == N) {
			cout << i + 1 << '\n';
			break;
		}
	}

	return 0;
}
