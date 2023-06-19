#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

constexpr int MAX = 100'000;

int visited[MAX + 1];
int parent[MAX + 1];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	memset(parent, -1, sizeof(parent));

	queue<int> q;
	q.push(N);
	visited[N] = 1;
	parent[N] = N;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (now == K) break;

		if (now - 1 >= 0 && !visited[now - 1]) {
			q.push(now - 1);
			visited[now - 1] = visited[now] + 1;
			parent[now - 1] = now;
		}

		if (now + 1 <= MAX && !visited[now + 1]) {
			q.push(now + 1);
			visited[now + 1] = visited[now] + 1;
			parent[now + 1] = now;
		}

		if (now * 2 <= MAX && !visited[now * 2]) {
			q.push(now * 2);
			visited[now * 2] = visited[now] + 1;
			parent[now * 2] = now;
		}
	}

	cout << visited[K] - 1 << '\n';

	vector<int> path;

	int now = K;
	path.emplace_back(now);

	while (parent[now] != now) {
		now = parent[now];
		path.emplace_back(now);
	}

	for (int i = path.size() - 1; i >= 0; i--)
		cout << path[i] << ' ';
	cout << '\n';

	return 0;
}
