#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	long long A, B;
	cin >> A >> B;

	int ans = 0;
	const long long N = sqrt(B);
	vector<bool> prime(N + 1, true);

	prime[0] = prime[1] = false;

	for (long long i = 2; i <= N; ++i) {
		if (!prime[i])
			continue;

		for (long long j = i * i; j <= N; j += i)
			prime[j] = false;

		long long power = i;

		while (true) {
			if (B / power < i)
				break;

			power *= i;

			if (A <= power)
				++ans;
		}
	}

	cout << ans << '\n';

	return 0;
}
