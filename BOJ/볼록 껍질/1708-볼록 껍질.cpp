#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
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

double ccw(const vector2& a, const vector2& b) {
	return a.cross(b);
}

double ccw(const vector2& p, const vector2& a, const vector2& b) {
	return ccw(a - p, b - p);
}

vector2 v0;

bool cmp(const vector2& lhs, const vector2& rhs) {
	double c = ccw(v0, lhs, rhs);
	return c ? c > 0 : lhs < rhs;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	vector<vector2> v(N);

	for (auto& [x, y] : v)
		cin >> x >> y;

	sort(v.begin(), v.end());
	v0 = v[0];
	sort(v.begin() + 1, v.end(), cmp);

	stack<int> stk({ 0, 1 });

	for (int next = 2; next < N; ++next) {
		while (stk.size() >= 2) {
			int first = stk.top();
			stk.pop();
			int second = stk.top();

			if (ccw(v[second], v[first], v[next]) > 0) {
				stk.push(first);
				break;
			}
		}

		stk.push(next);
	}

	cout << stk.size() << '\n';

	return 0;
}
