#include <iostream>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	int cnt = 1;
	bool possible = false;

	long long now = N;
	long long power = 1;

	while (N / power)
		power *= 10;

	for (; cnt <= K; ++cnt) {
		now %= K;

		if (!now) {
			possible = true;
			break;
		}

		now = now * power + N;
	}

	cout << (possible ? cnt : -1) << '\n';

	return 0;
}
