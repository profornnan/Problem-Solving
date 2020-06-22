#include <iostream>
#include <queue>
#include <algorithm>
#define sws ios::sync_with_stdio(false), cin.tie(NULL);
using namespace std;

const int mod = 1'000'000'007;

int main(void)
{
	sws;
	freopen("input.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		int n;
		long long c, amount = 1;
		cin >> n;
		priority_queue<long long> pq;
		for (int i = 0; i < n; i++) {
			cin >> c;
			pq.push(-c);
		}
		while(true) {
			if (pq.size() == 1)
				break;
			long long a = pq.top();
			pq.pop();
			long long b = pq.top();
			pq.pop();
			amount = ((amount % mod) * (a * b % mod)) % mod;
			pq.push(-1 * a * b);
		}
		cout << amount << '\n';
	}
	return 0;
}
