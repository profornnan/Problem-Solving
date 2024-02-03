#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

constexpr int dx[]{ -1, 1 };

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	int ans = 0;
	deque<int> ranking(N);

	for (int i = 0; i < N; ++i)
		cin >> ranking[i];

	while (ranking.size() > 1) {
		auto maxIter = max_element(ranking.begin(), ranking.end());
		int idx = maxIter - ranking.begin();
		int diff = ranking[idx];

		for (int i = 0; i < 2; ++i) {
			int nidx = idx + dx[i];

			if (nidx < 0 || nidx >= ranking.size())
				continue;

			diff = min(diff, ranking[idx] - ranking[nidx]);
		}

		ans += diff;
		ranking.erase(maxIter);
	}

	cout << ans << '\n';

	return 0;
}
