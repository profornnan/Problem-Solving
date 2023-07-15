#include <iostream>
#include <functional>
#include <vector>
#include <queue>
using namespace std;

using pii = pair<int, int>;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	vector<pii> lecture(N);

	for (auto& [st, en] : lecture)
		cin >> st >> en;

	sort(lecture.begin(), lecture.end());

	priority_queue<int, vector<int>, greater<int>> pq;

	auto [ignore, en] = lecture[0];
	pq.push(en);

	for (int i = 1; i < N; ++i) {
		auto [st, en] = lecture[i];
		pq.push(en);

		if (pq.top() <= st)
			pq.pop();
	}

	cout << pq.size() << '\n';

	return 0;
}
