#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

constexpr int INF = 987654321;
constexpr int N = 5;
constexpr int dx[]{ 1, 0, -1, 0 };
constexpr int dy[]{ 0, -1, 0, 1 };

int ans = INF;
int dp[1 << N];
bool block[N * N];
vector<int> init;
vector<int> path;

int calcDist(int initIdx, int state) {
	if (initIdx >= init.size())
		return 0;

	int ret = dp[state];

	if (ret != -1)
		return ret;

	ret = INF;

	for (int pathIdx = 0; pathIdx < init.size(); ++pathIdx) {
		if (state & (1 << pathIdx))
			continue;

		const int p = init[initIdx];
		const int q = path[pathIdx];

		ret = min(ret, abs(p / N - q / N) + abs(p % N - q % N) + calcDist(initIdx + 1, state | (1 << pathIdx)));
	}

	return ret;
}

void placeBlock(int prev, int cnt) {
	if (cnt >= init.size()) {
		queue<int> q;
		int visited = 0;
		int cnt = 0;

		q.push(path[0]);
		visited |= (1 << path[0]);

		while (!q.empty()) {
			const int now = q.front();
			const int y = now / N;
			const int x = now % N;
			q.pop();

			++cnt;

			for (int dir = 0; dir < 4; ++dir) {
				const int ny = y + dy[dir];
				const int nx = x + dx[dir];

				if (ny < 0 || ny >= N || nx < 0 || nx >= N)
					continue;

				const int next = ny * N + nx;

				if (!block[next])
					continue;

				if (visited & (1 << next))
					continue;

				q.push(next);
				visited |= (1 << next);
			}
		}

		if (cnt != init.size())
			return;

		memset(dp, -1, sizeof(dp));

		ans = min(ans, calcDist(0, 0));

		return;
	}

	for (int now = prev + 1; now < N * N; ++now) {
		block[now] = true;
		path.push_back(now);
		placeBlock(now, cnt + 1);
		path.pop_back();
		block[now] = false;
	}
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			char ch;
			cin >> ch;

			if (ch == '*')
				init.push_back(y * N + x);
		}
	}

	placeBlock(-1, 0);

	cout << ans << '\n';

	return 0;
}
