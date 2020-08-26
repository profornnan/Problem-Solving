#include <iostream>
#include <vector>
#include <algorithm>
#define sws ios::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

int N, K, W;
vector<int> time;
vector<vector<int> > adj;
vector<int> dp;

int dfs(int now) {
	if (dp[now] != -1)
		return dp[now];
	int &ret = dp[now];
	ret = 0;
	for (int i = 0; i < adj[now].size(); i++) {
		int next = adj[now][i];
		ret = max(ret, dfs(next));
	}
	ret += time[now];
	return ret;
}

int main(void)
{
	sws;
	freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	while (T--) {
		cin >> N >> K;
		time = vector<int>(N);
		adj = vector<vector<int> >(N, vector<int>());
		dp = vector<int>(N, -1);
		for (int i = 0; i < N; i++)
			cin >> time[i];
		for (int i = 0; i < K; i++) {
			int x, y;
			cin >> x >> y;
			adj[y - 1].push_back(x - 1);
		}
		cin >> W;
		cout << dfs(W - 1) << '\n';
	}
	return 0;
}
