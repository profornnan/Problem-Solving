#include <iostream>
using namespace std;

int n;
int triangle[500][500], d[500][500];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			cin >> triangle[i][j];
		}
	}
	d[0][0] = triangle[0][0];
	for (int i = 1; i < n; i++) {
		d[i][0] = d[i - 1][0] + triangle[i][0];
		d[i][i] = d[i - 1][i - 1] + triangle[i][i];
		for (int j = 1; j < i; j++) {
			if (d[i - 1][j - 1] >= d[i - 1][j])
				d[i][j] = d[i - 1][j - 1];
			else
				d[i][j] = d[i - 1][j];
			d[i][j] += triangle[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = ans > d[n - 1][i] ? ans : d[n - 1][i];
	cout << ans << '\n';
	return 0;
}
