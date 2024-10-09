#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <cmath>
using namespace std;

struct vector2 {
	int x;
	int y;

	vector2(int x = 0, int y = 0) : x(x), y(y) {}

	bool operator<(const vector2& rhs) const {
		return x != rhs.x ? x < rhs.x : y < rhs.y;
	}

	vector2 operator-(const vector2& rhs) const {
		return vector2(x - rhs.x, y - rhs.y);
	}

	int cross(const vector2& rhs) const {
		return x * rhs.y - rhs.x * y;
	}

	double norm() const {
		return sqrt(x * x + y * y);
	}
};

int ccw(const vector2& a, const vector2& b) {
	return a.cross(b);
}

int ccw(const vector2& p, const vector2& a, const vector2& b) {
	return ccw(a - p, b - p);
}

vector2 v0;

bool cmp(const vector2& lhs, const vector2& rhs) {
	int c = ccw(v0, lhs, rhs);
	return c ? c > 0 : lhs < rhs;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cout << fixed;
	cout.precision(2);

	int T = 0;

	while (true) {
		int N;
		cin >> N;

		if (!N)
			break;

		vector<vector2> v(N);

		for (auto& [x, y] : v)
			cin >> x >> y;

		sort(v.begin(), v.end());
		v0 = v[0];
		sort(v.begin() + 1, v.end(), cmp);

		vector<int> hull;

		for (int next = 0; next < N; ++next) {
			while (hull.size() >= 2) {
				const int first = hull.back();
				hull.pop_back();
				const int second = hull.back();

				if (ccw(v[second], v[first], v[next]) >= 0) {
					hull.push_back(first);
					break;
				}
			}

			hull.push_back(next);
		}

		double ans = numeric_limits<double>::max();

		for (int i = 0; i < hull.size(); ++i) {
			const vector2& p = v[hull[i]];
			const vector2& a = v[hull[(i + 1) % hull.size()]];

			double n = (a - p).norm();
			double maxDist = 0;

			for (int j = 0; j < hull.size(); ++j) {
				const vector2& b = v[hull[j]];
				maxDist = max(maxDist, abs(ccw(p, a, b)) / n);
			}

			ans = min(ans, maxDist);
		}

		cout << "Case " << ++T << ": " << ceil(ans * 100) / 100 << '\n';
	}

	return 0;
}
