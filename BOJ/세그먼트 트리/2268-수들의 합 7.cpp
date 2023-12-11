#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

enum {
	SUM,
	MODIFY
};

struct SegTree {
	vector<long long> tree;

	SegTree(const int& n) {
		int h = ceil(log2(n));
		int sz = (1 << (h + 1));
		vector<long long>(sz).swap(tree);
	}

	void update(int cur, int start, int end, const int left, const int right, const int k) {
		if (end < left || right < start) return;

		if (start == end) {
			tree[cur] = k;
			return;
		}

		int mid = start + (end - start) / 2;
		update(cur * 2, start, mid, left, right, k);
		update(cur * 2 + 1, mid + 1, end, left, right, k);
		tree[cur] = tree[cur * 2] + tree[cur * 2 + 1];
	}

	long long query(int cur, int start, int end, const int left, const int right) {
		if (end < left || right < start) return 0;
		if (left <= start && end <= right) return tree[cur];

		int mid = start + (end - start) / 2;
		return query(cur * 2, start, mid, left, right) + query(cur * 2 + 1, mid + 1, end, left, right);
	}
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	SegTree segTree(N);

	for (int m = 0; m < M; ++m) {
		int cmd, left, right, idx, k;

		cin >> cmd;

		if (cmd == SUM) {
			cin >> left >> right;
			if (left > right) swap(left, right);
			cout << segTree.query(1, 1, N, left, right) << '\n';
		}
		else if (cmd == MODIFY) {
			cin >> idx >> k;
			segTree.update(1, 1, N, idx, idx, k);
		}
	}

	return 0;
}
