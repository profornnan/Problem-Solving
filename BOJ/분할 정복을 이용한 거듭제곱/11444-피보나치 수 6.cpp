#include <iostream>
#include <unordered_map>
using namespace std;

constexpr int MOD = 1'000'000'007;

unordered_map<long long, long long> um{ {0, 0}, {1, 1}, {2, 1} };

long long fibo(long long n) {
	if (um.find(n) != um.end())
		return um[n];

	long long ret{};

	ret = (n & 1)
		? (fibo((n + 1) / 2) * fibo((n + 1) / 2) + fibo((n - 1) / 2) * fibo((n - 1) / 2)) % MOD
		: fibo(n / 2) * (2 * fibo((n / 2) - 1) + fibo(n / 2)) % MOD;

	um.insert({ n, ret });

	return ret;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	long long n;
	cin >> n;

	cout << fibo(n) << '\n';

	return 0;
}
