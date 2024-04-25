#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<pair<int, int>> person;

	for (int i = 0; i < N; ++i) {
		int st, en;
		cin >> st >> en;
		if (st > en) person.push_back({ en, st });
	}

	if (person.empty()) {
		cout << M << '\n';
		return 0;
	}

	sort(person.begin(), person.end());

	int ans = 0;
	int prev = person[0].first;

	for (const auto& [st, en] : person) {
		if (prev >= en)
			continue;

		ans += en - max(prev, st);
		prev = en;
	}

	cout << M + static_cast<long long>(ans) * 2 << '\n';

	return 0;
}
