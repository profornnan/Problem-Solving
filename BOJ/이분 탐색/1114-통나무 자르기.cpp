#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int L, K, C;
	cin >> L >> K >> C;

	vector<int> pos(K);

	for (auto& p : pos)
		cin >> p;

	pos.push_back(0);
	pos.push_back(L);

	sort(pos.begin(), pos.end());
	pos.erase(unique(pos.begin(), pos.end()), pos.end());

	int ans{}, firstPiece{};
	int left = 0;
	int right = L;

	vector<int> pieces;

	for (int i = pos.size() - 1; i >= 1; --i) {
		pieces.push_back(pos[i] - pos[i - 1]);
		left = max(left, pieces.back());
	}

	while (left <= right) {
		int mid = left + (right - left) / 2;
		int now = 0;
		int cnt = 0;

		for (const auto& piece : pieces) {
			now += piece;

			if (now <= mid)
				continue;

			now = piece;
			++cnt;
		}

		if (cnt <= C) {
			ans = mid;
			firstPiece = cnt == C ? now : pieces.back();
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	cout << ans << ' ' << firstPiece << '\n';

	return 0;
}
