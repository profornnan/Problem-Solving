#include <iostream>
#include <algorithm>
using namespace std;

constexpr long long INF = 2e18;
constexpr int MAX_N = 100'000;

int T, N;
long long pos[MAX_N + 1];
long long psum[MAX_N + 1];
long long ppsum[MAX_N + 1];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> T;

	while (T--) {
		cin >> N;

		for (int i = 1; i <= N; ++i)
			cin >> pos[i];

		for (int i = 1; i <= N; ++i) {
			int cnt;
			cin >> cnt;
			psum[i] = psum[i - 1] + cnt;
			ppsum[i] = ppsum[i - 1] + cnt * pos[i];
		}

		long long minPos = 0;
		long long minDist = INF;

		for (int i = 1; i <= N; ++i) {
			const long long dist = ppsum[N] - 2 * ppsum[i] - (psum[N] - 2 * psum[i]) * pos[i];

			if (minDist > dist) {
				minDist = dist;
				minPos = pos[i];
			}
		}

		cout << minPos << '\n';
	}

	return 0;
}
