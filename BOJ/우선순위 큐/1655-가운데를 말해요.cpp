#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

constexpr int INF = 987654321;

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	int N, num;
	priority_queue<int> lpq(1, -INF);
	priority_queue<int, vector<int>, greater<int>> rpq(1, INF);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num;
		num < lpq.top() ? lpq.push(num) : rpq.push(num);

		if (lpq.size() < rpq.size()) {
			lpq.push(rpq.top());
			rpq.pop();
		}
		else if (lpq.size() > rpq.size() + 1) {
			rpq.push(lpq.top());
			lpq.pop();
		}

		cout << lpq.top() << '\n';
	}

	return 0;
}
