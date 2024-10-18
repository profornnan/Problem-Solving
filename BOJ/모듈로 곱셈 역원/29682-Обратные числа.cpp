#include <iostream>
#include <tuple>
using namespace std;

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

	int a, m;
	cin >> a >> m;

	cout << modInverse(a, m) << '\n';

	return 0;
}
