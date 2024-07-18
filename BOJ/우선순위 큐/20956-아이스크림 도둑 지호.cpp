#include <iostream>
#include <vector>
#include <queue>
using namespace std;

inline int getSign(const int num) {
	return (num > 0) - (num < 0);
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<bool> visited(N + 1);
	priority_queue<pair<int, int>> ascPq;
	priority_queue<pair<int, int>> descPq;

	for (int i = 1; i <= N; ++i) {
		int amount;
		cin >> amount;
		ascPq.push({ amount, -i });
		descPq.push({ amount, i });
	}

	bool rev = false;

	while (M) {
		auto& pq = rev ? descPq : ascPq;
		auto [amount, id] = pq.top();
		id *= getSign(id);

		if (visited[id]) {
			pq.pop();
			continue;
		}

		cout << id << '\n';
		visited[id] = true;

		if (amount % 7 == 0)
			rev = !rev;

		--M;
	}

	return 0;
}
