#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

constexpr int MAX_M = 1'000'000;

struct SegTree {
	vector<int> tree;

	SegTree(int n) {
		int h = ceil(log2(n));
		int sz = (1 << (h + 1));
		vector<int>(sz).swap(tree);
	}

	void update(int cur, int start, int end, const int idx) {
		if (end < idx || idx < start) return;

		++tree[cur];

		if (start == end) return;

		int mid = start + (end - start) / 2;
		update(cur * 2, start, mid, idx);
		update(cur * 2 + 1, mid + 1, end, idx);
	}

	int query(int cur, int start, int end, const int left, const int right) {
		if (right < start || end < left) return 0;
		if (left <= start && end <= right) return tree[cur];

		int mid = start + (end - start) / 2;
		return query(cur * 2, start, mid, left, right) + query(cur * 2 + 1, mid + 1, end, left, right);
	}
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	int m;
	vector<int> dest(MAX_M + 1);
	SegTree segTree(N);

	for (int i = 1; i <= N; ++i) {
		cin >> m;
		dest[m] = i;
	}

	long long ans{};

	for (int i = 1; i <= N; ++i) {
		cin >> m;
		int idx = dest[m];
		ans += segTree.query(1, 1, N, idx + 1, N);
		segTree.update(1, 1, N, idx);
	}

	cout << ans << '\n';

	return 0;
}
