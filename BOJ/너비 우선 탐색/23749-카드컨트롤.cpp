#include <iostream>
#include <queue>
using namespace std;

constexpr int MAX_S = 1'024;

int N;
bool visited[MAX_S];

bool isWin(int state) {
	int p1 = 0;
	int p2 = 0;

	while (state) {
		if ((state & 3) == 2)
			++p1;
		else if ((state & 3) == 1)
			++p2;

		state >>= 2;
	}

	return p1 > p2;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	int st = 0;
	int top = 1;

	for (int i = 0; i < 2 * N; ++i) {
		char ch;
		cin >> ch;
		st = st * 2 + (ch == 'O');
		top <<= 1;
	}

	top >>= 1;

	int cnt = 0;
	queue<int> q;

	q.push(st);
	visited[st] = true;

	while (!q.empty()) {
		int sz = q.size();

		while (sz--) {
			const int now = q.front();
			q.pop();

			if (isWin(now)) {
				cout << cnt << '\n';
				return 0;
			}

			for (int digit = 1; digit < top; digit <<= 1) {
				int next = now & digit ? top : 0;
				next += (now & ~(digit * 2 - 1)) >> 1;
				next += now & (digit - 1);

				if (visited[next])
					continue;

				q.push(next);
				visited[next] = true;
			}
		}

		++cnt;
	}

	return 0;
}
