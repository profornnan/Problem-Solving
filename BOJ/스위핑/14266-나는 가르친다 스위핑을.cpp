#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Pos {
	int x;
	int y;

	double slope() const {
		return static_cast<double>(x) / y;
	}
};

struct Info {
	double slope;
	int amt;

	bool operator<(const Info& rhs) const {
		return slope != rhs.slope ? slope < rhs.slope : amt > rhs.amt;
	}
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	vector<Info> info(N * 2);

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 2; ++j) {
			Pos pos;
			cin >> pos.x >> pos.y;
			info[i * 2 + j] = { pos.slope(), 1 };
		}

		info[i * 2].slope > info[i * 2 + 1].slope ? info[i * 2].amt = -1 : info[i * 2 + 1].amt = -1;
	}

	sort(info.begin(), info.end());

	int cnt = 0;
	int ans = 0;

	for (const auto& [slope, amt] : info) {
		cnt += amt;
		ans = max(ans, cnt);
	}

	cout << ans << '\n';

	return 0;
}
