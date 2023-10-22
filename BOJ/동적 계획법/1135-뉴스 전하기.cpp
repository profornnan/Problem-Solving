#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

constexpr int MAX_N = 50;

int N;
int dp[MAX_N];
vector<int> adj[MAX_N];

int dfs(int now) {
	if (!adj[now].size())
		return 0;

	int& ret = dp[now];

	if (ret != -1)
		return ret;

	int sz = static_cast<int>(adj[now].size());
	vector<int> cost;

	for (const int& next : adj[now])
		cost.push_back(dfs(next));

	sort(cost.begin(), cost.end());

	for (int i = 0; i < sz; ++i)
		ret = max(ret, cost[i] + sz - i);

	return ret;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	for (int child = 0; child < N; ++child) {
		int parent;
		cin >> parent;

		if (parent == -1)
			continue;

		adj[parent].push_back(child);
	}

	memset(dp, -1, sizeof(dp));

	cout << dfs(0) << '\n';

	return 0;
}
