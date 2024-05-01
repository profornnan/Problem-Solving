#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct Range {
	int st;
	int en;
	long long cnt;

	bool operator<(const Range& rhs) const {
		return cnt != rhs.cnt ? cnt > rhs.cnt : st > rhs.st;
	}
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int L, N;
	cin >> L;

	vector<int> S(L + 1);

	for (int i = 1; i <= L; ++i)
		cin >> S[i];

	sort(S.begin(), S.end());

	cin >> N;

	priority_queue<Range> pq;
	vector<int> ans;

	for (int i = 1; i <= L; ++i) {
		const int st = S[i - 1];
		const int en = S[i];

		pq.push({ en, en, 1 });

		if (st + 1 <= en - 1)
			pq.push({ st + 1, en - 1, en - st - 1 });
	}

	while (!pq.empty()) {
		auto [st, en, cnt] = pq.top();
		pq.pop();

		ans.push_back(st);

		if (ans.size() >= N)
			break;

		if (st == en)
			continue;

		ans.push_back(en);

		if (st + 1 <= en - 1)
			pq.push({ st + 1, en - 1, cnt + en - st - 1 });

		if (ans.size() >= N)
			break;
	}

	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i] << ' ';

	for (int i = 1; i < N - ans.size() + 1; ++i)
		cout << S[L] + i << ' ';

	cout << '\n';

	return 0;
}
