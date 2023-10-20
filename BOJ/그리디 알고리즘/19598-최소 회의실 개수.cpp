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

	vector<pii> meeting(N);
	priority_queue<int, vector<int>, greater<int>> pq;

	for (auto& [st, en] : meeting)
		cin >> st >> en;

	sort(meeting.begin(), meeting.end());

	int ans = 0;

	for (const auto [st, en] : meeting) {
		while (!pq.empty() && pq.top() <= st)
			pq.pop();

		pq.push(en);
		ans = max(ans, static_cast<int>(pq.size()));
	}

	cout << ans << '\n';

	return 0;
}
