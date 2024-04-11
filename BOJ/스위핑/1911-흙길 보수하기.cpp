#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, L;
	cin >> N >> L;

	vector<pair<int, int>> puddles(N);

	for (auto& [st, en] : puddles)
		cin >> st >> en;

	sort(puddles.begin(), puddles.end());

	int ans = 0;
	int endPos = 0;

	for (const auto& [st, en] : puddles) {
		if (endPos >= en)
			continue;

		if (endPos < st)
			endPos = st;

		const int diff = en - endPos;
		const int cnt = diff / L + (diff % L ? 1 : 0);

		endPos += cnt * L;
		ans += cnt;
	}

	cout << ans << '\n';

	return 0;
}
