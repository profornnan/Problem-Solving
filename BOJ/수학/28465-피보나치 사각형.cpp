#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int a, b, x, y;
	cin >> a >> b >> x >> y;

	while (true) {
		if (a < b) {
			swap(a, b);
			swap(x, y);
		}

		const int c = a - b;

		if (c <= x && x < b) {
			int ans = 0;

			while (b) {
				a -= b;
				swap(a, b);
				++ans;
			}

			cout << ans << '\n';
			break;
		}
		else if (x < c) {
			a = c;
		}
		else if (b <= x) {
			a = c;
			x -= b;
		}
	}

	return 0;
}
