#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Range {
	int st;
	int en;

	bool operator<(const Range& rhs) const {
		return st != rhs.st ? st < rhs.st : en < rhs.en;
	}
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	vector<Range> ranges(N);

	for (auto& [st, en] : ranges)
		cin >> st >> en;

	sort(ranges.begin(), ranges.end());

	int ans = 0;

	for (int i = 0; i < N; ++i) {
		int cnt = 0;

		for (int j = i + 1; j < N; ++j)
			if (ranges[j].en <= ranges[i].en)
				++cnt;

		ans = max(ans, cnt);
	}

	cout << ans << '\n';

	return 0;
}
