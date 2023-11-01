#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

constexpr int dx[]{ 1, 0, -1, 0 };
constexpr int dy[]{ 0, -1, 0, 1 };

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	vector<vector<int>> vec(N);

	for (int i = 0; i < N; ++i)
		vec[i].push_back(i);

	int prev = 0;
	int now = 1;

	while (true) {
		const int sz = vec[prev].size();

		if (now + sz - 1 >= N)
			break;

		for (int i = now - 1; i >= prev; --i)
			for (int j = 0; j < vec[i].size(); ++j)
				vec[now + j].push_back(vec[i][j]);

		prev = now;
		now += sz;
	}

	vector<int> order1;
	vector<vector<int>> adj1(N);

	for (int i = prev; i < N; ++i)
		for (const auto& num : vec[i])
			order1.push_back(num);

	int sz = vec[prev].size();

	for (int i = now; i < N; ++i)
		vec[i].insert(vec[i].end(), sz - vec[i].size(), -1);

	for (int y = prev; y < N; ++y) {
		for (int x = 0; x < sz; ++x) {
			const int u = vec[y][x];

			if (u == -1)
				break;

			for (int dir = 0; dir < 4; ++dir) {
				int ny = y + dy[dir];
				int nx = x + dx[dir];

				if (ny < prev || ny >= N || nx < 0 || nx >= sz)
					continue;

				const int v = vec[ny][nx];

				if (v == -1)
					continue;

				if (u > v)
					continue;

				adj1[u].push_back(v);
			}
		}
	}

	for (int i = 0; i < N; ++i)
		vec[i] = { i };

	prev = 0;
	now = N / 2;

	for (int i = prev; i < now; ++i)
		for (int j = vec[i].size() - 1; j >= 0; --j)
			vec[N - 1 + prev - i].push_back(vec[i][j]);

	prev = now;
	now = now + (N - now) / 2;

	for (int i = prev; i < now; ++i)
		for (int j = vec[i].size() - 1; j >= 0; --j)
			vec[N - 1 + prev - i].push_back(vec[i][j]);

	vector<int> order2;
	vector<vector<int>> adj2(N);

	for (int i = now; i < N; ++i)
		for (const auto& num : vec[i])
			order2.push_back(num);

	sz = vec[now].size();

	for (int y = now; y < N; ++y) {
		for (int x = 0; x < sz; ++x) {
			const int u = vec[y][x];

			for (int dir = 0; dir < 4; ++dir) {
				int ny = y + dy[dir];
				int nx = x + dx[dir];

				if (ny < now || ny >= N || nx < 0 || nx >= sz)
					continue;

				const int v = vec[ny][nx];

				if (u > v)
					continue;

				adj2[u].push_back(v);
			}
		}
	}

	int ans = 0;
	vector<int> fishbowl(N);

	for (auto& fish : fishbowl)
		cin >> fish;

	while (true) {
		int maxFish = fishbowl[0];
		int minFish = fishbowl[0];

		for (const auto& fish : fishbowl) {
			maxFish = max(maxFish, fish);
			minFish = min(minFish, fish);
		}

		if (maxFish - minFish <= K)
			break;

		++ans;

		for (auto& fish : fishbowl)
			if (fish == minFish)
				fish++;

		vector<int> change(N);

		for (int now = 0; now < N; ++now) {
			for (const auto& next : adj1[now]) {
				const int nowFish = fishbowl[now];
				const int nextFish = fishbowl[next];

				int d = abs(nowFish - nextFish) / 5;

				if (d == 0)
					continue;

				if (nowFish > nextFish) {
					change[now] -= d;
					change[next] += d;
				}
				else if (nowFish < nextFish) {
					change[now] += d;
					change[next] -= d;
				}
			}
		}

		for (int i = 0; i < N; ++i)
			fishbowl[i] += change[i];

		for (int i = 0; i < N; ++i)
			change[i] = fishbowl[order1[i]];

		fishbowl = change;

		vector<int>(N).swap(change);

		for (int now = 0; now < N; ++now) {
			for (const auto& next : adj2[now]) {
				const int nowFish = fishbowl[now];
				const int nextFish = fishbowl[next];

				int d = abs(nowFish - nextFish) / 5;

				if (d == 0)
					continue;

				if (nowFish > nextFish) {
					change[now] -= d;
					change[next] += d;
				}
				else if (nowFish < nextFish) {
					change[now] += d;
					change[next] -= d;
				}
			}
		}

		for (int i = 0; i < N; ++i)
			fishbowl[i] += change[i];

		for (int i = 0; i < N; ++i)
			change[i] = fishbowl[order2[i]];

		fishbowl = change;
	}

	cout << ans << '\n';

	return 0;
}
