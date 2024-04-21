#include <iostream>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	if (N <= K) {
		cout << "0\n";
		return 0;
	}

	int prev = 0;

	while (K--) {
		int now = 1;

		while (now <= N)
			now <<= 1;

		N -= now / 2;
		prev = now / 2;
	}

	cout << (N == 0 ? 0 : prev - N) << '\n';

	return 0;
}
