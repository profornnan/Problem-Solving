#include <iostream>
#include <algorithm>
using namespace std;

constexpr int MAX_N = 1'000;

int getSign(const int num) {
	return (num > 0) - (num < 0);
}

int N;
int diff[MAX_N + 1];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> diff[i];

	for (int i = 0; i < N; ++i) {
		int target;
		cin >> target;
		diff[i] -= target;
	}

	int cnt = 0;

	while (true) {
		bool updated = false;
		int prev = 0;
		int sign = getSign(diff[0]);
		int minAbs = sign * diff[0];

		for (int now = 0; now <= N; ++now) {
			if (getSign(diff[now]) != sign) {
				for (int i = prev; i < now; ++i)
					diff[i] -= sign * minAbs;

				cnt += minAbs;
				updated = true;
				prev = now;
				sign = getSign(diff[now]);
				minAbs = sign * diff[now];
			}

			minAbs = min(minAbs, sign * diff[now]);
		}

		if (!updated)
			break;
	}

	cout << cnt << '\n';

	return 0;
}
