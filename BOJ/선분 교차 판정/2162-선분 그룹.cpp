#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct UnionFind {
	vector<int> parent;
	vector<int> cnt;

	UnionFind(int sz) : parent(sz, -1), cnt(sz, 1) {}

	int Find(int x) {
		if (parent[x] == -1) return x;
		return parent[x] = Find(parent[x]);
	}

	void Union(int a, int b) {
		int pa = Find(a);
		int pb = Find(b);
		if (pa == pb) return;
		parent[pb] = pa;
		cnt[pa] += cnt[pb];
		cnt[pb] = 0;
	}
};

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

	int N;
	cin >> N;

	vector<pair<vector2, vector2>> lineSegments;
	UnionFind uf(N);

	for (int i = 0; i < N; ++i) {
		double x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		lineSegments.push_back({ {x1, y1}, {x2, y2} });
	}

	for (int u = 0; u < N; ++u) {
		for (int v = u + 1; v < N; ++v) {
			const auto& [a, b] = lineSegments[u];
			const auto& [c, d] = lineSegments[v];

			if (segmentIntersects(a, b, c, d))
				uf.Union(u, v);
		}
	}

	int groupCnt{};
	int maxLineCnt{};

	for (int i = 0; i < N; ++i) {
		if (uf.parent[i] == -1)
			++groupCnt;

		maxLineCnt = max(maxLineCnt, uf.cnt[i]);
	}

	cout << groupCnt << '\n' << maxLineCnt << '\n';

	return 0;
}
