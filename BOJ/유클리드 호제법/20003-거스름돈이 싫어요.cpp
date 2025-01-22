#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
	return a * b / gcd(a, b);
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	long long numer, denom;
	cin >> N >> numer >> denom;

	const long long g = gcd(numer, denom);

	numer /= g;
	denom /= g;

	for (int i = 1; i < N; ++i) {
		long long a, b;
		cin >> a >> b;

		const long long g = gcd(a, b);

		a /= g;
		b /= g;

		numer = gcd(numer, a);
		denom = lcm(denom, b);
	}

	cout << numer << ' ' << denom << '\n';

	return 0;
}
