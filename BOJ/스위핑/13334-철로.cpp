#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using pii = pair<int, int>;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	vector<pii> person(N);
	priority_queue<int, vector<int>, greater<int>> pq;

	for (auto& [en, st] : person) {
		cin >> st >> en;
		if (st > en) swap(st, en);
	}

	int D;
	cin >> D;

	sort(person.begin(), person.end());

	int ans = 0;

	for (const auto [en, st] : person) {
		while (!pq.empty() && pq.top() < en - D)
			pq.pop();

		if (st >= en - D)
			pq.push(st);
		ans = max(ans, static_cast<int>(pq.size()));
	}

	cout << ans << '\n';

	return 0;
}
