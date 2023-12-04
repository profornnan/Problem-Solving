#include <iostream>
#include <queue>
using namespace std;

long long bfs(int n) {
	int cnt = 0;
	queue<long long> q;

	for (int i = 0; i <= 9; ++i)
		q.push(i);

	while (!q.empty()) {
		long long now = q.front();
		q.pop();
		++cnt;

		if (cnt == n)
			return now;

		for (int i = 0; i < now % 10; ++i) {
			long long next = now * 10 + i;
			q.push(next);
		}
	}

	return -1;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	cout << bfs(N) << '\n';

	return 0;
}
