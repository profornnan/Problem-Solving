#include <iostream>
#include <cstring>
#define sws ios::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

const int MOD = 1'000'000'007;
int N, M, P;
int dp[101][101];

int dfs(int now, int song) {
	if (now >= P)
		return song == N ? 1 : 0;

	if (dp[now][song] != -1)
		return dp[now][song];

	long long res = 0;

	if (song < N)
		res = (res + (long long)(N - song) * dfs(now + 1, song + 1)) % MOD;
	
	if (song > M)
		res = (res + (long long)(song - M) * dfs(now + 1, song)) % MOD;

	return dp[now][song] = res;
}

int main(void) {
	sws;
	memset(dp, -1, sizeof(dp));

	cin >> N >> M >> P;

	cout << dfs(0, 0) << '\n';

	return 0;
}
