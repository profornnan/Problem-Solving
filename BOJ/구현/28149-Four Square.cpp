#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

constexpr int MAX_R = 2'000;
constexpr int N = 4;

struct Rec {
	int h;
	int w;
};

int R;
bool visited[MAX_R][MAX_R];
Rec rec[N];
vector<int> path{ 1, 2, 3 };
bool possible;

bool putRec(const int sy, const int sx, const int h, const int w) {
	for (int y = 0; y < h; ++y) {
		for (int x = 0; x < w; ++x) {
			if (visited[sy + y][sx + x])
				return false;

			visited[sy + y][sx + x] = true;
		}
	}

	return true;
}

void removeRec(const int sy, const int sx, const int h, const int w) {
	for (int y = 0; y < h; ++y)
		for (int x = 0; x < w; ++x)
			visited[sy + y][sx + x] = false;
}

void dfs(const int level, int sy, int sx) {
	if (possible)
		return;

	if (level >= N - 1) {
		possible = true;
		return;
	}

	while (visited[sy][sx]) {
		if (++sx >= R) {
			sx = 0;
			++sy;
		}
	}

	auto [h, w] = rec[path[level]];

	for (int i = 0; i < 2; ++i) {
		if (sy + h <= R && sx + w <= R) {
			if (putRec(sy, sx, h, w))
				dfs(level + 1, sy, sx);

			removeRec(sy, sx, h, w);
		}

		swap(h, w);
	}
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int area = 0;

	for (int i = 0; i < N; ++i) {
		int h, w;
		cin >> h >> w;

		rec[i] = { h, w };
		area += h * w;
	}

	R = sqrt(area);

	if (R * R != area) {
		cout << "0\n";
		return 0;
	}

	for (int y = 0; y < rec[0].h; ++y)
		for (int x = 0; x < rec[0].w; ++x)
			visited[y][x] = true;

	do {
		dfs(0, 0, 0);

		if (possible)
			break;

	} while (next_permutation(path.begin(), path.end()));

	cout << possible << '\n';

	return 0;
}
