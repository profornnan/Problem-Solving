#include <iostream>
#include <queue>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	priority_queue<int> pq;

	for (int i = 0; i < N; i++) {
		int card;
		cin >> card;
		pq.push(-card);
	}

	int ans = 0;

	while (pq.size() > 1) {
		int card1 = -pq.top();
		pq.pop();

		int card2 = -pq.top();
		pq.pop();

		ans += card1 + card2;
		pq.push(-card1 - card2);
	}

	cout << ans << '\n';

	return 0;
}
