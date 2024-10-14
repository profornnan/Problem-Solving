#include <iostream>
#include <cmath>
using namespace std;

int len(long long num) {
	int ret = 0;

	while (num) {
		++ret;
		num /= 10;
	}

	return ret;
}

long long reverse(long long num) {
	long long ret = 0;

	while (num) {
		ret = ret * 10 + num % 10;
		num /= 10;
	}

	return ret;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		long long N;
		cin >> N;

		int cnt = 0;

		while (N) {
			const long long half = N % static_cast<long long>(pow(10, (len(N) + 1) / 2));

			if (half > 1) {
				N -= half - 1;
				cnt += half - 1;
				continue;
			}

			const long long rev = reverse(N);

			N = half == 1 && N != rev ? rev : N - 1;
			++cnt;
		}

		cout << "Case #" << tc << ": " << cnt << '\n';
	}

	return 0;
}
