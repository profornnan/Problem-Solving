#include <iostream>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cout << "Scenario #" << tc << ":\n";

		int N;
		cin >> N;

		int P = 2;
		int ans = 1;

		while (P * P <= N) {
			int cnt = 0;

			while (N % P == 0) {
				N /= P;
				++cnt;
			}

			ans *= (2 * cnt + 1);
			++P;
		}

		if (N > 1)
			ans *= 3;

		cout << ans / 2 + 1 << "\n\n";
	}

	return 0;
}
