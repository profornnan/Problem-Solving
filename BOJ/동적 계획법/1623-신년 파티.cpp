#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

constexpr int MAX_N = 200'000;

int N;
int score[MAX_N + 1];
vector<int> adj[MAX_N + 1];
int dp[MAX_N + 1][2];
vector<int> ans;

int dfs(const int now, const bool selected) {
	int& ret = dp[now][selected];

	if (ret != -1)
		return ret;

	ret = selected ? score[now] : 0;

	for (const auto& next : adj[now])
		ret += selected ? dfs(next, false) : max(dfs(next, true), dfs(next, false));

	return ret;
}

void path(const int now, const bool selected) {
	if (selected)
		ans.push_back(now);

	for (const auto& next : adj[now])
		path(next, selected ? false : dp[next][true] > dp[next][false]);
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; ++i)
		cin >> score[i];

	for (int c = 2; c <= N; ++c) {
		int p;
		cin >> p;
		adj[p].push_back(c);
	}

	memset(dp, -1, sizeof(dp));

	cout << dfs(1, true) << ' ' << dfs(1, false) << '\n';

	path(1, true);
	sort(ans.begin(), ans.end());

	for (const auto& id : ans)
		cout << id << ' ';
	cout << "-1\n";

	vector<int>().swap(ans);

	path(1, false);
	sort(ans.begin(), ans.end());

	for (const auto& id : ans)
		cout << id << ' ';
	cout << "-1\n";

	return 0;
}
