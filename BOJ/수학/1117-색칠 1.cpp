#include <iostream>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	long long W, H, f, c, x1, y1, x2, y2;
	cin >> W >> H >> f >> c >> x1 >> y1 >> x2 >> y2;

	const long long b = f < W - f ? f : W - f;
	long long k = 0;

	if (b <= x1)
		k = x2 - x1;
	else if (b <= x2)
		k = 2 * (b - x1) + x2 - b;
	else
		k = 2 * (x2 - x1);

	cout << W * H - (c + 1) * k * (y2 - y1) << '\n';

	return 0;
}
