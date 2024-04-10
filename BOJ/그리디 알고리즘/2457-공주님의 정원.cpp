#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

constexpr int START_DATE = 301;
constexpr int END_DATE = 1130;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	vector<pair<int, int>> flowers(N);

	for (auto& [st, en] : flowers) {
		int stM, stD, enM, enD;
		cin >> stM >> stD >> enM >> enD;
		st = stM * 100 + stD;
		en = enM * 100 + enD;
	}

	sort(flowers.begin(), flowers.end());

	int cnt = 0;
	int idx = 0;
	int endDate = START_DATE;

	while (true) {
		if (endDate > END_DATE)
			break;

		int nEndDate = endDate;

		while (idx < N) {
			const auto& [st, en] = flowers[idx];

			if (endDate < st)
				break;

			nEndDate = max(nEndDate, en);
			++idx;
		}

		if (endDate == nEndDate)
			break;

		endDate = nEndDate;
		++cnt;
	}

	cout << (endDate > END_DATE ? cnt : 0) << '\n';

	return 0;
}
