#include <iostream>
#include <cstring>
#include <algorithm>
#define sws ios::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

const int INF = 987654321;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };
int N, M;
char board[50][50];
bool visited[50][50];
int dp[50][50];

bool is_in_range(int y, int x) {
	if (y < 0 || y >= N || x < 0 || x >= M)
		return false;
	return true;
}

int solve(int y, int x) {
	if (!is_in_range(y, x) || board[y][x] == 'H')
		return 0;

	if (visited[y][x])
		return INF;

	if (dp[y][x] != -1)
		return dp[y][x];

	visited[y][x] = true;

	int &ret = dp[y][x];
	ret = 0;
	int dist = board[y][x] - '0';

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i] * dist;
		int nx = x + dx[i] * dist;
		int n_cnt = 1 + solve(ny, nx);
		ret = max(ret, n_cnt);
	}

	visited[y][x] = false;

	if (ret > INF)
		ret = INF;

	return ret;
}

int main(void)
{
	sws;
	freopen("input.txt", "r", stdin);
	cin >> N >> M;
	memset(dp, -1, sizeof(dp));

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> board[y][x];
		}
	}

	int ans = solve(0, 0);

	if (ans == INF)
		ans = -1;

	cout << ans << '\n';

	return 0;
}
