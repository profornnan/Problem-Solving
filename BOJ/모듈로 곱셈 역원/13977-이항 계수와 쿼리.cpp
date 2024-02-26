#include <iostream>
#include <tuple>
using namespace std;

constexpr int MAX_N = 4'000'000;
constexpr int MOD = 1'000'000'007;

int factorial[MAX_N + 1];

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

	factorial[0] = factorial[1] = 1;

	for (int i = 2; i <= MAX_N; ++i)
		factorial[i] = (static_cast<long long>(factorial[i - 1]) * i) % MOD;

	int M;
	cin >> M;

	for (int m = 0; m < M; ++m) {
		int N, K;
		cin >> N >> K;
		cout << (static_cast<long long>(factorial[N]) * modInverse((static_cast<long long>(factorial[K]) * factorial[N - K]) % MOD, MOD)) % MOD << '\n';
	}

	return 0;
}
