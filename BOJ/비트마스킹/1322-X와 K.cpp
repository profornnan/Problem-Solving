#include <iostream>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	long long X, K;
	cin >> X >> K;

	long long ans = 0;

	while (K) {
		long long cnt = 1;
		long long temp = ~X & -~X;

		while (cnt << 1 <= K) {
			temp <<= 1;

			if (!(temp & X))
				cnt <<= 1;
		}

		K -= cnt;
		ans += temp;
	}

	cout << ans << '\n';

	return 0;
}
