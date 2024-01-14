#include <iostream>
using namespace std;

struct vector2 {
	double x;
	double y;

	vector2(double x = 0, double y = 0) : x(x), y(y) {}

	bool operator<(const vector2& rhs) const {
		return x != rhs.x ? x < rhs.x : y < rhs.y;
	}

	vector2 operator-(const vector2& rhs) const {
		return vector2(x - rhs.x, y - rhs.y);
	}

	double cross(const vector2& rhs) const {
		return x * rhs.y - rhs.x * y;
	}
};

double ccw(vector2 a, vector2 b) {
	return a.cross(b);
}

double ccw(vector2 p, vector2 a, vector2 b) {
	return ccw(a - p, b - p);
}

bool segmentIntersects(vector2 a, vector2 b, vector2 c, vector2 d) {
	double ab = ccw(a, b, c) * ccw(a, b, d);
	double cd = ccw(c, d, a) * ccw(c, d, b);

	if (ab == 0 && cd == 0) {
		if (b < a) swap(a, b);
		if (d < c) swap(c, d);
		return !(b < c || d < a);
	}

	return ab <= 0 && cd <= 0;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	vector2 a, b, c, d;

	cin >> a.x >> a.y >> b.x >> b.y;
	cin >> c.x >> c.y >> d.x >> d.y;

	cout << (segmentIntersects(a, b, c, d) ? 1 : 0) << '\n';

	return 0;
}
