#include <iostream>
#include <queue>
using namespace std;

constexpr int MAX_L = 100;

int MAP[MAX_L + 1];
int visited[MAX_L + 1];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N + M; ++i) {
		int u, v;
		cin >> u >> v;
		MAP[u] = v;
	}

	queue<int> q;
	q.push(1);
	visited[1] = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 1; i <= 6; ++i) {
			int next = now + i;

			if (next > MAX_L)
				break;

			if (MAP[next])
				next = MAP[next];

			if (visited[next])
				continue;

			visited[next] = visited[now] + 1;
			q.push(next);
		}
	}

	cout << visited[MAX_L] - 1 << '\n';

	return 0;
}
