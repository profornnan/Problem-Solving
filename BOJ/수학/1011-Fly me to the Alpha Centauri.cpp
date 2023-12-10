#include <iostream>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		int x, y;
		cin >> x >> y;

		y -= x;

		int z = 1;
		long long sum = 0;

		while (y > sum + z * 2) {
			sum += z * 2;
			++z;
		}

		if (sum + z >= y)
			cout << 2 * z - 1 << '\n';
		else
			cout << 2 * z << '\n';
	}

	return 0;
}
