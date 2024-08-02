#include <iostream>
#include <queue>
using namespace std;

constexpr int MAX_N = 99'999;

int N, T, G;
bool visited[MAX_N + 1];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> T >> G;

	int cnt = 0;
	queue<int> q;

	q.push(N);
	visited[N] = true;

	while (!q.empty() && cnt <= T) {
		int sz = q.size();

		while (sz--) {
			int now = q.front();
			q.pop();

			if (now == G) {
				cout << cnt << '\n';
				return 0;
			}

			int next = now + 1;

			if (next <= MAX_N && !visited[next]) {
				q.push(next);
				visited[next] = true;
			}

			next = now * 2;

			if (next == 0 || next > MAX_N)
				continue;

			for (int digit = 10'000; digit >= 1; digit /= 10) {
				if (next / digit) {
					next -= digit;
					break;
				}
			}

			if (visited[next])
				continue;

			q.push(next);
			visited[next] = true;
		}

		++cnt;
	}

	cout << "ANG\n";

	return 0;
}
