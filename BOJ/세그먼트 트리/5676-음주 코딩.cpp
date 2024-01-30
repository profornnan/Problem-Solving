#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int getSign(int num) {
	return (num > 0) - (num < 0);
}

struct SegTree {
	vector<int> tree;

	SegTree(const vector<int>& nums) {
		int h = ceil(log2(nums.size()));
		int sz = (1 << (h + 1));

		vector<int>(sz, 1).swap(tree);

		init(1, 1, nums.size(), nums);
	}

	int init(int cur, int start, int end, const vector<int>& nums) {
		if (start == end) return tree[cur] = getSign(nums[start - 1]);

		int mid = start + (end - start) / 2;
		return tree[cur] = init(cur * 2, start, mid, nums) * init(cur * 2 + 1, mid + 1, end, nums);
	}

	void update(int cur, int start, int end, const int idx, const int num) {
		if (idx < start || end < idx) return;

		if (start == end) {
			tree[cur] = getSign(num);
			return;
		}

		int mid = start + (end - start) / 2;
		update(cur * 2, start, mid, idx, num);
		update(cur * 2 + 1, mid + 1, end, idx, num);
		tree[cur] = tree[cur * 2] * tree[cur * 2 + 1];
	}

	int query(int cur, int start, int end, const int left, const int right) {
		if (right < start || end < left) return 1;
		if (left <= start && end <= right) return tree[cur];

		int mid = start + (end - start) / 2;
		return query(cur * 2, start, mid, left, right) * query(cur * 2 + 1, mid + 1, end, left, right);
	}
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, K;

	while (cin >> N >> K) {
		vector<int> nums(N);

		for (auto& num : nums)
			cin >> num;

		SegTree segTree(nums);

		for (int k = 0; k < K; ++k) {
			char cmd;
			int idx, num, left, right;

			cin >> cmd;

			if (cmd == 'C') {
				cin >> idx >> num;
				segTree.update(1, 1, N, idx, num);
			}
			else if (cmd == 'P') {
				cin >> left >> right;
				int res = segTree.query(1, 1, N, left, right);
				cout << (res == 0 ? '0' : (res > 0 ? '+' : '-'));
			}
		}

		cout << '\n';
	}

	return 0;
}
