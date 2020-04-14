#include <iostream>
#define sws ios::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

int n, b, c;
int a[1000000];
long long ans;

int main(void)
{
	sws;
	freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> b >> c;
	ans = n;
	for (int i = 0; i < n; i++) {
		a[i] -= b;
		if (a[i] > 0) {
			ans += a[i] / c;
			if (a[i] % c)
				ans += 1;
		}
	}
	cout << ans << '\n';
	return 0;
}
