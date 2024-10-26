#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

constexpr int INF = 21e8;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	long long dist = 0;
	priority_queue<int> lpq(1, -INF);
	priority_queue<int, vector<int>, greater<int>> rpq(1, INF);

	for (int i = 0; i < N; ++i) {
		int x, y;
		cin >> x >> y;

		const int prev = lpq.top();

		y < lpq.top() ? lpq.push(y) : rpq.push(y);

		if (lpq.size() < rpq.size()) {
			lpq.push(rpq.top());
			rpq.pop();
		}
		else if (lpq.size() > rpq.size() + 1) {
			rpq.push(lpq.top());
			lpq.pop();
		}

		dist += abs(x);
		dist += lpq.size() == rpq.size() ? abs(lpq.top() - prev) : 0;
		dist += abs(lpq.top() - y);

		cout << lpq.top() << ' ' << dist << '\n';
	}

	return 0;
}
