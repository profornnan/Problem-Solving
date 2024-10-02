#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct vector2 {
	int x;
	int y;
	int id;

	vector2(int x = 0, int y = 0, int id = 0) : x(x), y(y), id(id) {}

	bool operator<(const vector2& rhs) const {
		return x != rhs.x ? x < rhs.x : y < rhs.y;
	}

	vector2 operator-(const vector2& rhs) const {
		return vector2(x - rhs.x, y - rhs.y);
	}

	int cross(const vector2& rhs) const {
		return x * rhs.y - rhs.x * y;
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

	int C;
	cin >> C;

	while (C--) {
		int N;
		cin >> N;

		vector<vector2> v;

		for (int i = 0; i < N; ++i) {
			int x, y;
			cin >> x >> y;
			v.push_back({ x, y, i });
		}

		sort(v.begin(), v.end());
		v0 = v[0];
		sort(v.begin() + 1, v.end(), cmp);

		for (int i = v.size() - 1; i >= 1; --i) {
			if (ccw(v0, v[i], v[i - 1]) == 0)
				continue;

			reverse(v.begin() + i, v.end());
			break;
		}

		for (const auto& [x, y, id] : v)
			cout << id << ' ';
		cout << '\n';
	}

	return 0;
}
