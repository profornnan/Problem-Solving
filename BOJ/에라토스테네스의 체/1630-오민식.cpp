#include <iostream>
#include <vector>
using namespace std;

constexpr int MOD = 987'654'321;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	long long ans = 1;
	vector<bool> prime(N + 1, true);

	prime[0] = prime[1] = false;

	for (int i = 2; i <= N; ++i) {
		if (!prime[i])
			continue;

		for (int j = i * 2; j <= N; j += i)
			prime[j] = false;

		int temp = N;

		while (temp / i) {
			ans = (ans * i) % MOD;
			temp /= i;
		}
	}

	cout << ans << '\n';

	return 0;
}
