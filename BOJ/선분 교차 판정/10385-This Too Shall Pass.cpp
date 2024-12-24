#include <iostream>
#include <vector>
using namespace std;

struct vector2 {
	double x;
	double y;

	vector2(double x = 0, double y = 0) : x(x), y(y) {}

	bool operator<(const vector2& rhs) const {
		return x != rhs.x ? x < rhs.x : y < rhs.y;
	}

	vector2 operator+(const vector2& rhs) const {
		return vector2(x + rhs.x, y + rhs.y);
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

const vector<vector<vector2>> dv{
	{{-1, -1}, {-1, 2}},
	{{-1, 2}, {2, 2}},
	{{2, 2}, {2, -1}},
	{{2, -1}, {-1, -1}}
};

bool isInside(const vector2& off, const vector2& def) {
	return (def.x - 1 <= off.x && off.x <= def.x + 2) && (def.y - 1 <= off.y && off.y <= def.y + 2);
}

bool isPossible(const vector2& off1, const vector2& off2, const vector<vector2>& defense) {
	for (const auto& def : defense) {
		if (isInside(off1, def) || isInside(off2, def))
			return false;

		for (int i = 0; i < 4; ++i)
			if (segmentIntersects(off1, off2, def + dv[i][0], def + dv[i][1]))
				return false;
	}

	return true;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int T = 0;

	while (true) {
		int R, C, N, M;
		cin >> R >> C >> N >> M;

		if (R == 0 && C == 0 && N == 0 && M == 0)
			break;

		cout << "Case " << ++T << ":";

		vector<vector2> offense(N);

		for (auto& [x, y] : offense) {
			cin >> y >> x;
			y += 0.5;
			x += 0.5;
		}

		vector<vector2> defense(M);

		for (auto& [x, y] : defense)
			cin >> y >> x;

		for (int i = 1; i < N; ++i)
			if (isPossible(offense[0], offense[i], defense))
				cout << ' ' << i + 1;

		cout << '\n';
	}

	return 0;
}
