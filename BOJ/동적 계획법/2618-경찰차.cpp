#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

constexpr int MAX_W = 1'000;

struct Point {
	int y;
	int x;
};

int N, W;
vector<Point> points;
int dp[MAX_W + 2][MAX_W + 2];

int calcDist(const Point& lhs, const Point& rhs) {
	return abs(rhs.y - lhs.y) + abs(rhs.x - lhs.x);
}

int dfs(int firstIdx, int secondIdx) {
	int& ret = dp[firstIdx][secondIdx];

	if (ret != -1)
		return ret;

	if (firstIdx == W + 1 || secondIdx == W + 1)
		return ret = 0;

	const int nextIdx = max(firstIdx, secondIdx) + 1;

	const Point& firstP = points[firstIdx];
	const Point& secondP = points[secondIdx];
	const Point& nextP = points[nextIdx];

	return ret = min(calcDist(firstP, nextP) + dfs(nextIdx, secondIdx), calcDist(secondP, nextP) + dfs(firstIdx, nextIdx));
}

void path(int firstIdx, int secondIdx) {
	if (firstIdx == W + 1 || secondIdx == W + 1)
		return;

	const int nextIdx = max(firstIdx, secondIdx) + 1;

	const Point& firstP = points[firstIdx];
	const Point& secondP = points[secondIdx];
	const Point& nextP = points[nextIdx];

	if (calcDist(firstP, nextP) + dp[nextIdx][secondIdx] < calcDist(secondP, nextP) + dp[firstIdx][nextIdx]) {
		cout << "1\n";
		path(nextIdx, secondIdx);
	}
	else {
		cout << "2\n";
		path(firstIdx, nextIdx);
	}
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> W;

	points = { { 1, 1 }, { N, N } };

	for (int i = 0; i < W; ++i) {
		int y, x;
		cin >> y >> x;
		points.push_back({ y, x });
	}

	memset(dp, -1, sizeof(dp));

	cout << dfs(0, 1) << '\n';

	path(0, 1);

	return 0;
}
