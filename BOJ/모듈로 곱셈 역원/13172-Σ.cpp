#include <iostream>
#include <tuple>
using namespace std;

constexpr int MOD = 1'000'000'007;

tuple<int, int, int> extendedGCD(int a, int b) {
	if (b == 0) return { a, 1, 0 };
	const auto [gcd, x, y] = extendedGCD(b, a % b);
	return { gcd, y, x - (a / b) * y };
}

int modInverse(int a, int mod) {
	const auto [gcd, x, y] = extendedGCD(a, mod);
	return gcd > 1 ? -1 : (x + mod) % mod;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int M;
	cin >> M;

	long long ans = 0;

	for (int m = 0; m < M; ++m) {
		int N, S;
		cin >> N >> S;
		ans = (ans + static_cast<long long>(S) * modInverse(N, MOD)) % MOD;
	}

	cout << ans << '\n';

	return 0;
}
