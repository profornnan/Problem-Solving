#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	vector<pair<int, int>> lectures(N);
	priority_queue<int, vector<int>, greater<int>> pq;

	for (auto& [day, pay] : lectures)
		cin >> pay >> day;

	sort(lectures.begin(), lectures.end());

	for (const auto& [day, pay] : lectures) {
		pq.push(pay);

		if (pq.size() > day)
			pq.pop();
	}

	int sum = 0;

	while (!pq.empty()) {
		sum += pq.top();
		pq.pop();
	}

	cout << sum << '\n';

	return 0;
}
