#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	if (N < 8) {
		cout << "-1\n";
		return 0;
	}

	vector<bool> prime(N + 1, true);

	prime[0] = prime[1] = false;

	for (int i = 2; i <= N; ++i)
		if (prime[i])
			for (int j = i * 2; j <= N; j += i)
				prime[j] = false;

	const int M = N & 1 ? 5 : 4;

	cout << 2 << ' ' << M - 2 << ' ';

	for (int i = 2; i <= N; ++i) {
		if (prime[i] && prime[N - M - i]) {
			cout << i << ' ' << N - M - i << '\n';
			return 0;
		}
	}

	return 0;
}
