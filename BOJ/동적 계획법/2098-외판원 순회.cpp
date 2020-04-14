#include <iostream>
#define sws ios::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

const int INF = 987654321;
int n;
int cost[16][16];
int d[16][1 << 16];

int solve(int start, int now, int visited) {
	if (visited == (1 << n) - 1) {
		if (cost[now][start])
			return cost[now][start];
		return INF;
	}
	if (d[now][visited])
		return d[now][visited];
	int& ret = d[now][visited] = INF;
	for (int next = 0; next < n; next++) {
		if (now == next)
			continue;
		if (cost[now][next] && !(visited & (1 << next))) {
			int n_cost = solve(start, next, visited | (1 << next));
			if (n_cost != INF)
				n_cost += cost[now][next];
			ret = ret < n_cost ? ret : n_cost;
		}
	}
	return ret;
}

int main(void)
{
	sws;
	freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> cost[i][j];
	cout << solve(0, 0, 1 << 0) << '\n';
	return 0;
}
