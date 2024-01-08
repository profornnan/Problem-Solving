#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	vector<pair<int, int>> station(N);

	for (auto& [pos, amount] : station)
		cin >> pos >> amount;

	int dest, fuel;
	cin >> dest >> fuel;

	sort(station.begin(), station.end());

	int now = fuel, idx{}, ans{};
	priority_queue<int> pq;

	while (now < dest) {
		while (idx < N && station[idx].first <= now)
			pq.push(station[idx++].second);

		if (pq.empty()) {
			ans = -1;
			break;
		}

		now += pq.top();
		pq.pop();
		++ans;
	}

	cout << ans << '\n';

	return 0;
}
