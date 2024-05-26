#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	vector<pair<int, int>> cows(N);
	priority_queue<int, vector<int>, greater<int>> pq;

	for (auto& [deadline, milk] : cows)
		cin >> milk >> deadline;

	sort(cows.begin(), cows.end());

	for (const auto& [deadline, milk] : cows) {
		pq.push(milk);

		if (pq.size() > deadline)
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
