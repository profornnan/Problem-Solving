#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

constexpr int MAX_N = 9'999;
constexpr int DIGIT = 1'000;

bool prime[MAX_N + 1];
bool visited[MAX_N + 1];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	memset(prime, 1, sizeof(prime));

	prime[0] = prime[1] = false;

	for (int i = 2; i <= MAX_N; ++i)
		if (prime[i])
			for (int j = i * i; j <= MAX_N; j += i)
				prime[j] = false;

	int T;
	cin >> T;

	while (T--) {
		int st, en;
		cin >> st >> en;

		bool possible = false;
		int cnt = 0;
		queue<int> q;

		memset(visited, 0, sizeof(visited));

		q.push(st);
		visited[st] = true;

		while (!q.empty()) {
			if (visited[en]) {
				possible = true;
				break;
			}

			int sz = q.size();

			while (sz--) {
				int now = q.front();
				q.pop();

				for (int digit = 1; digit <= DIGIT; digit *= 10) {
					int base = now - (now % (digit * 10)) + (now % digit);

					for (int i = 0; i <= 9; ++i) {
						int next = base + i * digit;

						if (next < DIGIT)
							continue;

						if (!prime[next])
							continue;

						if (visited[next])
							continue;

						q.push(next);
						visited[next] = true;
					}
				}
			}

			++cnt;
		}

		if (possible)
			cout << cnt << '\n';
		else
			cout << "Impossible\n";
	}

	return 0;
}
