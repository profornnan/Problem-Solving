#include <iostream>
using namespace std;

int s, t, a, b;

int main(void) {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cout << '#' << tc << ' ';
		cin >> s >> t >> a >> b;

		if (b == 1) {
			if ((t - s) % a == 0)
				cout << (t - s) / a << '\n';
			else
				cout << "-1\n";
			continue;
		}

		int cnt = 0;

		while (true) {
			if (s == t) break;

			if (s > t) {
				cnt = -1;
				break;
			}

			if (t % b == 0 && t / b >= s)
				t /= b;
			else
				t -= a;

			cnt++;
		}

		cout << cnt << '\n';
	}
	return 0;
}
