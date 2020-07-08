#include <iostream>
#include <queue>
#include <algorithm>
#define sws ios::sync_with_stdio(false), cin.tie(NULL);
using namespace std;

int n, k;
int sensor[10000];

int main(void)
{
	sws;
	freopen("input.txt", "r", stdin);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> sensor[i];
	sort(sensor, sensor + n);
	priority_queue<int> pq;
	long long answer = 0;
	for (int i = 0; i < n - 1; i++) {
		pq.push(sensor[i + 1] - sensor[i]);
		answer += sensor[i + 1] - sensor[i];
	}
	for (int i = 0; i < k - 1; i++) {
		if (pq.empty())
			break;
		answer -= pq.top();
		pq.pop();
	}
	cout << answer << '\n';
	return 0;
}
