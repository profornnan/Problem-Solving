#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

constexpr int MOD = 10000;
char visited[MOD];
int parent[MOD];
char path[MOD];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		int A, B;
		cin >> A >> B;

		memset(visited, -1, sizeof(visited));
		queue<int> q;

		q.push(A);
		parent[A] = A;
		visited[A] = 0;

		while (!q.empty()) {
			int now = q.front();
			q.pop();

			if (now == B) {
				int idx = 0;
				int n = B;

				while (parent[n] != n) {
					path[idx++] = visited[n];
					n = parent[n];
				}

				for (int i = idx - 1; i >= 0; --i)
					cout << path[i];
				cout << '\n';

				break;
			}

			// D
			int next = (now * 2) % MOD;

			if (visited[next] == -1) {
				q.push(next);
				parent[next] = now;
				visited[next] = 'D';
			}

			// S
			next = (MOD + now - 1) % MOD;

			if (visited[next] == -1) {
				q.push(next);
				parent[next] = now;
				visited[next] = 'S';
			}

			// L
			next = (now * 10) % MOD + (now * 10) / MOD;

			if (visited[next] == -1) {
				q.push(next);
				parent[next] = now;
				visited[next] = 'L';
			}

			// R
			next = ((now % 10) * MOD + now) / 10;

			if (visited[next] == -1) {
				q.push(next);
				parent[next] = now;
				visited[next] = 'R';
			}
		}
	}

	return 0;
}
