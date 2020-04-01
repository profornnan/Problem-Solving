#include <iostream>
#include <limits>
using namespace std;

int s, c;
int len[1'000'000];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	cin >> s >> c;
	int left = 1, right = 1;
	for (int i = 0; i < s; i++) {
		cin >> len[i];
		right = right > len[i] ? right : len[i];
	}
	while (left <= right) {
		int mid = (right - left) / 2 + left;
		int cnt = 0;
		for (int i = 0; i < s; i++)
			cnt += len[i] / mid;
		if (cnt >= c)
			left = mid + 1;
		else
			right = mid - 1;
	}
	long long ans = 0;
	for (int i = 0; i < s; i++)
		ans += len[i];
	ans -= c * (long long)right;
	cout << ans << '\n';
	return 0;
}
