#include <iostream>
#include <queue>
#define sws ios::sync_with_stdio(false), cin.tie(NULL);
using namespace std;

int main(void)
{
	sws;
	freopen("input.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		int k, d;
		long long answer = 0;
		priority_queue<long long> pq;
		cin >> k;
		for (int i = 0; i < k; i++) {
			cin >> d;
			pq.push(-d);
		}
		while (true) {
			if (pq.size() == 1)
				break;
			long long a = -pq.top();
			pq.pop();
			long long b = -pq.top();
			pq.pop();
			answer += a + b;
			pq.push(-(a + b));
		}
		cout << answer << '\n';
	}
	return 0;
}
