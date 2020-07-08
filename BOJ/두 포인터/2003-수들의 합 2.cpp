#include <iostream>
#define sws ios::sync_with_stdio(false), cin.tie(NULL);
using namespace std;

int n, m;
int arr[10000];

int main(void)
{
	sws;
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int lo = 0, hi = 0, sum = 0, cnt = 0;
	while (lo != n || hi != n) {
		if (sum >= m || hi == n)
			sum -= arr[lo++];
		else
			sum += arr[hi++];
		if (sum == m)
			cnt++;
	}
	cout << cnt << '\n';
	return 0;
}
