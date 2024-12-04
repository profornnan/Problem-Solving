#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

constexpr int MAX_N = 200'000;

int N, M, cnt;
int st[MAX_N + 1];
int en[MAX_N + 1];
vector<int> adj[MAX_N + 1];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < N - 1; ++i) {
		int from, to;
		cin >> from >> to;
		adj[from].push_back(to);
	}

	deque<int> dq;
	dq.push_front(1);

	while (!dq.empty()) {
		const int now = dq.front();
		dq.pop_front();

		if (st[now])
			en[now] = cnt;
		else {
			st[now] = ++cnt;
			dq.push_front(now);

			sort(adj[now].begin(), adj[now].end(), greater<int>());

			for (const auto& next : adj[now])
				dq.push_front(next);
		}
	}

	int prevSt = 1;

	for (int i = 0; i < M; ++i) {
		int dest;
		cin >> dest;

		if (prevSt > en[dest]) {
			cout << i << '\n';
			return 0;
		}

		prevSt = max(prevSt, st[dest]);
	}

	cout << M << '\n';

	return 0;
}
