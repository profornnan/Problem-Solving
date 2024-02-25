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

	int N, K;
	cin >> N >> K;

	K = K > N - K ? K : N - K;

	long long numer = 1;
	long long denom = 1;

	for (int i = N; i > K; --i)
		numer = (numer * i) % MOD;

	for (int i = N - K; i > 0; --i)
		denom = (denom * i) % MOD;

	cout << (numer * modInverse(denom, MOD)) % MOD << '\n';

	return 0;
}
