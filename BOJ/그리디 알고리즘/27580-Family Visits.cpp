#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

constexpr int MAX_N = 1'000;
constexpr int MAX_D = 1'000;

int N, D;
int mess[MAX_N + 1];
int clean[MAX_N + 1];
int day[MAX_D + 1];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> D;

	for (int i = 1; i <= N; ++i)
		cin >> mess[i] >> clean[i];

	for (int i = 1; i <= D; ++i)
		cin >> day[i];

	int ans = 0;

	for (int d = 1; d <= D; ++d) {
		int totalMess = 0;
		int remainClean = 0;
		priority_queue<int> pq;

		for (int i = day[d]; i >= day[d - 1] + 1; --i) {
			totalMess += mess[i];

			if (remainClean) {
				const int sub = min(totalMess, remainClean);
				totalMess -= sub;
				remainClean -= sub;
			}

			pq.push(clean[i]);

			while (totalMess && !pq.empty()) {
				int nowClean = pq.top();
				pq.pop();

				const int sub = min(totalMess, nowClean);
				totalMess -= sub;
				nowClean -= sub;
				remainClean += nowClean;
				++ans;
			}

			if (totalMess) {
				cout << "-1\n";
				return 0;
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
