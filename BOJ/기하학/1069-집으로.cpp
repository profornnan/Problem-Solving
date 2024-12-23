#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cout << fixed;
	cout.precision(13);

	int x, y, d, t;
	cin >> x >> y >> d >> t;

	const double dist = sqrt(x * x + y * y);
	const int jump = dist / d;
	const double remain = dist - jump * d;

	double ans = min({ dist, remain + jump * t, (jump + 1) * d - dist + (jump + 1) * t });

	if (jump > 0)
		ans = min(ans, static_cast<double>(jump + 1) * t);
	else if (dist < d)
		ans = min(ans, 2.0 * t);

	cout << ans << '\n';

	return 0;
}
