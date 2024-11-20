#include <iostream>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	long long N;
	cin >> N;

	for (long long i = 2; i * i <= N * 2; ++i) {
		const long long sub = N - i * (i + 1) / 2;

		if (!(sub % i))
			cout << sub / i + 1 << ' ' << sub / i + i << '\n';
	}

	return 0;
}
