#include <iostream>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, P;
	cin >> N >> P;

	const int MAX = N / P + !!(N % P);

	int prev = 0;
	int now = 0;

	for (int i = 1; i <= N; ++i) {
		cin >> now;

		const int diff = now - prev;

		if ((diff == 0 || diff == 1) && now <= MAX && now <= i && i <= now * P) {
			prev = now;
			continue;
		}

		cout << "NO\n";
		return 0;
	}

	cout << "YES\n";

	return 0;
}
