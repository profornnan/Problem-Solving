#include <iostream>
#include <algorithm>
#include <cstring>
#define sws ios::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

const int INF = 987654321;
int N, K;
int W[100];
int V[100];
int dp[100][100001];

int dfs(int level, int weight) {
	if (weight > K)
		return -INF;

	if (level >= N)
		return 0;

	if (dp[level][weight] != -1)
		return dp[level][weight];

	return dp[level][weight] = max(dfs(level + 1, weight), dfs(level + 1, weight + W[level]) + V[level]);
}

int main(void) {
	sws;

	memset(dp, -1, sizeof(dp));

	cin >> N >> K;

	for (int i = 0; i < N; i++)
		cin >> W[i] >> V[i];

	cout << dfs(0, 0) << '\n';

	return 0;
}
