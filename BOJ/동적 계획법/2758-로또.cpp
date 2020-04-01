#include <iostream>
using namespace std;

int t, n, m;
long long d[11][2001];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	for (int i = 1; i <= 2000; i++)
		d[1][i] = i;
	for (int i = 2; i <= 10; i++) {
		for (int j = i; j <= 2000; j++) {
			d[i][j] = d[i][j - 1] + d[i - 1][j / 2];
		}
	}
	cin >> t;
	while (t--) {
		cin >> n >> m;
		cout << d[n][m] << '\n';
	}
	return 0;
}
