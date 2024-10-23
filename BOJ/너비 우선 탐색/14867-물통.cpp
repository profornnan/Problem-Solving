#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

int A, B, ea, eb;
queue<pair<int, int>> q;
set<pair<int, int>> visited;

void insert(const pair<int, int>& p) {
	if (visited.count(p))
		return;

	q.push(p);
	visited.insert(p);
}

int bfs() {
	int cnt = 0;

	q.push({ 0, 0 });
	visited.insert({ 0, 0 });

	while (!q.empty()) {
		int sz = q.size();

		while (sz--) {
			const auto [a, b] = q.front();
			q.pop();

			if (a == ea && b == eb)
				return cnt;

			// F(a)
			insert({ A, b });

			// F(b)
			insert({ a, B });

			// E(a)
			insert({ 0, b });

			// E(b)
			insert({ a, 0 });

			// M(a, b)
			int amt = min(a, B - b);
			insert({ a - amt, b + amt });

			// M(b, a)
			amt = min(A - a, b);
			insert({ a + amt, b - amt });
		}

		++cnt;
	}

	return -1;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> A >> B >> ea >> eb;

	cout << bfs() << '\n';

	return 0;
}
