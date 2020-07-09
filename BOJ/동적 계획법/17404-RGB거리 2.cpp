#include <iostream>
#include <cstring>
#include <algorithm>
#define sws ios::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

const int INF = 987654321;
int n;
int cost[1000][3];  // R = 0, G = 1, B = 2
int d[1000][3];

int main(void)
{
	sws;
	freopen("input.txt", "r", stdin);
	cin >> n;
	int ans = INF;
	for (int i = 0; i < n; i++)
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	for (int k = 0; k < 3; k++) {
		memset(d, 0, sizeof(d));
		for (int i = 0; i < 3; i++)
			d[0][0] = d[0][1] = d[0][2] = INF;
		d[0][k] = cost[0][k];
		for (int i = 1; i < n; i++) {
			d[i][0] = cost[i][0] + min(d[i - 1][1], d[i - 1][2]);
			d[i][1] = cost[i][1] + min(d[i - 1][0], d[i - 1][2]);
			d[i][2] = cost[i][2] + min(d[i - 1][0], d[i - 1][1]);
		}
		for (int i = 0; i < 3; i++) {
			if (i == k)
				continue;
			ans = min(ans, d[n - 1][i]);
		}
	}
	cout << ans << '\n';
	return 0;
}
