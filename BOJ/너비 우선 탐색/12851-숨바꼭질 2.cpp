#include <iostream>
#include <queue>
using namespace std;

constexpr int MAX = 100'000;

int N, K;
bool visited[MAX + 1];
int minSec = 21e8, cnt;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> K;

	queue<pair<int, int>> q;
	q.push({ N, 0 });

	while (!q.empty()) {
		int now = q.front().first;
		int sec = q.front().second;
		q.pop();

		visited[now] = true;

		if (minSec < sec) break;

		if (now == K) {
			minSec = sec;
			cnt++;
			continue;
		}

		if (now - 1 >= 0 && !visited[now - 1])
			q.push({ now - 1, sec + 1 });
		if (now + 1 <= MAX && !visited[now + 1])
			q.push({ now + 1, sec + 1 });
		if (now * 2 <= MAX && !visited[now * 2])
			q.push({ now * 2, sec + 1 });
	}

	cout << minSec << '\n' << cnt << '\n';

	return 0;
}
