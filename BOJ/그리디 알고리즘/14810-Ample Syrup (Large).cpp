#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

constexpr double PI = 3.1415926535897932;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cout << fixed;
	cout.precision(9);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		int N, K;
		cin >> N >> K;

		vector<pair<int, int>> pancakes(N);

		for (auto& [r, h] : pancakes)
			cin >> r >> h;

		sort(pancakes.begin(), pancakes.end());

		long long ans = 0;
		long long sideSum = 0;

		priority_queue<long long, vector<long long>, greater<long long>> pq;

		for (const auto& [r, h] : pancakes) {
			if (pq.size() >= K) {
				sideSum -= pq.top();
				pq.pop();
			}

			const long long top = 1LL * r * r;
			const long long side = 2LL * r * h;

			sideSum += side;
			pq.push(side);

			ans = max(ans, top + sideSum);
		}

		cout << "Case #" << tc << ": " << ans * PI << '\n';
	}

	return 0;
}
