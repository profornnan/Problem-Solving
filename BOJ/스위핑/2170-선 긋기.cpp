#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

constexpr int INF = 21e8;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	vector<pair<int, int>> lines(N);

	for (auto& [st, en] : lines)
		cin >> st >> en;

	sort(lines.begin(), lines.end());

	int ans = 0;
	int prev = -INF;

	for (const auto& [st, en] : lines) {
		if (prev >= en)
			continue;

		if (prev < st)
			prev = st;

		ans += en - prev;
		prev = en;
	}

	cout << ans << '\n';

	return 0;
}
