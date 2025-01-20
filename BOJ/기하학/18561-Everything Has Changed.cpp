#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cout << fixed;
	cout.precision(12);

	int T;
	cin >> T;

	while (T--) {
		int M;
		double R;
		cin >> M >> R;

		double ans = 2 * M_PI * R;

		for (int i = 0; i < M; ++i) {
			double x, y, r;
			cin >> x >> y >> r;

			const double d = sqrt(x * x + y * y);

			if (d >= r + R)
				continue;

			if (d < abs(r - R))
				continue;

			const double t1 = acos((d * d + r * r - R * R) / (2 * d * r)) * 2;
			const double t2 = acos((d * d + R * R - r * r) / (2 * d * R)) * 2;

			ans += t1 * r - t2 * R;
		}

		cout << ans << '\n';
	}

	return 0;
}
