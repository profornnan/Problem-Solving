#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct Cow {
	int st;
	int en;

	bool operator<(const Cow& rhs) const {
		if (st < rhs.st)
			return true;
		if (st > rhs.st)
			return false;
		return en < rhs.en;
	}
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int C, N;
	cin >> C >> N;

	vector<int> chickens(C);
	vector<Cow> cows(N);

	for (auto& pos : chickens)
		cin >> pos;

	for (auto& [st, en] : cows)
		cin >> st >> en;

	sort(chickens.begin(), chickens.end());
	sort(cows.begin(), cows.end());

	int ans{};
	int idx{};
	priority_queue<int, vector<int>, greater<int>> pq;

	for (const auto& pos : chickens) {
		while (idx < N && cows[idx].st <= pos)
			pq.push(cows[idx++].en);

		while (!pq.empty() && pq.top() < pos)
			pq.pop();

		if (pq.empty())
			continue;

		++ans;
		pq.pop();
	}

	cout << ans << '\n';

	return 0;
}
