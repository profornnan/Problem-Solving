#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

constexpr int INF = 21e8;

struct Cow {
	int pos;
	int id;

	bool operator<(const Cow& rhs) const {
		return pos < rhs.pos;
	}
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	vector<Cow> cows(N);
	vector<int> ids;

	for (auto& [pos, id] : cows) {
		cin >> pos >> id;
		ids.push_back(id);
	}

	sort(ids.begin(), ids.end());
	ids.erase(unique(ids.begin(), ids.end()), ids.end());

	vector<int> visited(ids.size());

	for (auto& [pos, id] : cows)
		id = lower_bound(ids.begin(), ids.end(), id) - ids.begin();

	sort(cows.begin(), cows.end());

	int ans = INF;
	int cnt = 0;
	int left = 0;
	int right = 0;

	while (true) {
		if (cnt >= ids.size()) {
			ans = min(ans, cows[right - 1].pos - cows[left].pos);

			--visited[cows[left].id];

			if (!visited[cows[left].id])
				--cnt;

			++left;
		}
		else {
			if (right >= N)
				break;

			if (!visited[cows[right].id])
				++cnt;

			++visited[cows[right].id];

			++right;
		}
	}

	cout << ans << '\n';

	return 0;
}
