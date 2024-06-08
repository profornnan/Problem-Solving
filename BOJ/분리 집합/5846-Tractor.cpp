#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

constexpr int MAX_N = 500;
constexpr int dx[]{ 1, 0 };
constexpr int dy[]{ 0, -1 };

struct Edge {
	int a;
	int b;
	int cost;

	bool operator<(const Edge& rhs) const {
		return cost < rhs.cost;
	}
};

int N;
int maxCnt = 1;
int MAP[MAX_N][MAX_N];
int parent[MAX_N * MAX_N];
int cnt[MAX_N * MAX_N];

int Find(int x) {
	if (parent[x] == -1) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
	int pa = Find(a);
	int pb = Find(b);

	if (pa == pb)
		return;

	parent[pb] = pa;
	cnt[pa] += cnt[pb];
	cnt[pb] = 0;

	maxCnt = max(maxCnt, cnt[pa]);
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	for (int y = 0; y < N; ++y)
		for (int x = 0; x < N; ++x)
			cin >> MAP[y][x];

	vector<Edge> edges;

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			for (int dir = 0; dir < 2; ++dir) {
				int ny = y + dy[dir];
				int nx = x + dx[dir];

				if (ny < 0 || ny >= N || nx < 0 || nx >= N)
					continue;

				edges.push_back({ y * N + x, ny * N + nx, abs(MAP[ny][nx] - MAP[y][x]) });
			}
		}
	}

	sort(edges.begin(), edges.end());

	fill(parent, parent + N * N, -1);
	fill(cnt, cnt + N * N, 1);

	int ans = 0;
	int idx = 0;

	while (true) {
		while (idx < edges.size()) {
			const auto& [a, b, cost] = edges[idx];

			if (cost > ans)
				break;

			Union(a, b);
			++idx;
		}

		if (maxCnt >= (N * N + 1) / 2)
			break;

		ans = edges[idx].cost;
	}

	cout << ans << '\n';

	return 0;
}
