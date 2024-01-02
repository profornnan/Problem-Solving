#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

struct SegTree {
	vector<long long> tree;

	SegTree(const vector<int>& nums) {
		int h = ceil(log2(nums.size()));
		int sz = (1 << (h + 1));

		vector<long long>(sz).swap(tree);

		init(1, 1, nums.size(), nums);
	}

	long long init(int cur, int start, int end, const vector<int>& nums) {
		if (start == end) return tree[cur] = nums[start - 1];

		int mid = start + (end - start) / 2;
		return tree[cur] = init(cur * 2, start, mid, nums) + init(cur * 2 + 1, mid + 1, end, nums);
	}

	void update(int cur, int start, int end, const int idx, const int num) {
		if (idx < start || end < idx) return;

		if (start == end) {
			tree[cur] = num;
			return;
		}

		int mid = start + (end - start) / 2;
		update(cur * 2, start, mid, idx, num);
		update(cur * 2 + 1, mid + 1, end, idx, num);
		tree[cur] = tree[cur * 2] + tree[cur * 2 + 1];
	}

	long long query(int cur, int start, int end, const int left, const int right) {
		if (right < start || end < left) return 0;
		if (left <= start && end <= right) return tree[cur];

		int mid = start + (end - start) / 2;
		return query(cur * 2, start, mid, left, right) + query(cur * 2 + 1, mid + 1, end, left, right);
	}
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, Q;
	cin >> N >> Q;

	vector<int> nums(N);
	for (int& num : nums) cin >> num;

	SegTree segTree(nums);

	for (int q = 0; q < Q; ++q) {
		int left, right, idx, num;
		cin >> left >> right >> idx >> num;

		if (left > right) swap(left, right);

		cout << segTree.query(1, 1, N, left, right) << '\n';
		segTree.update(1, 1, N, idx, num);
	}

	return 0;
}
