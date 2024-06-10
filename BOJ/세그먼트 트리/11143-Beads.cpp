#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct SegTree {
	vector<int> tree;

	SegTree(const int n) {
		int h = ceil(log2(n));
		int sz = (1 << (h + 1));
		vector<int>(sz).swap(tree);
	}

	void update(int cur, int start, int end, const int idx, const int plus) {
		if (idx < start || end < idx) return;

		if (start == end) {
			tree[cur] += plus;
			return;
		}

		const int mid = start + (end - start) / 2;
		update(cur * 2, start, mid, idx, plus);
		update(cur * 2 + 1, mid + 1, end, idx, plus);
		tree[cur] = tree[cur * 2] + tree[cur * 2 + 1];
	}

	int query(int cur, int start, int end, const int left, const int right) {
		if (right < start || end < left) return 0;
		if (left <= start && end <= right) return tree[cur];

		const int mid = start + (end - start) / 2;
		return query(cur * 2, start, mid, left, right) + query(cur * 2 + 1, mid + 1, end, left, right);
	}
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int T;
	cin >> T;

	while (T--) {
		int B, P, Q;
		cin >> B >> P >> Q;

		SegTree segTree(B);

		for (int i = 0; i < P + Q; ++i) {
			char cmd;
			int idx, plus, left, right;

			cin >> cmd;

			if (cmd == 'P') {
				cin >> idx >> plus;
				segTree.update(1, 1, B, idx, plus);
			}
			else if (cmd == 'Q') {
				cin >> left >> right;
				cout << segTree.query(1, 1, B, left, right) << '\n';
			}
		}
	}

	return 0;
}
