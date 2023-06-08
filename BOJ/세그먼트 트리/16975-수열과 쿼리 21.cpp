#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct SegTree {
	vector<long long> tree;
	vector<long long> lazy;

	SegTree(const vector<int>& nums) {
		int h = ceil(log2(nums.size()));
		int sz = (1 << (h + 1));

		vector<long long>(sz).swap(tree);
		vector<long long>(sz).swap(lazy);

		init(1, 1, nums.size(), nums);
	}

	long long init(int cur, int start, int end, const vector<int>& nums) {
		if (start == end) return tree[cur] = nums[start - 1];

		int mid = start + (end - start) / 2;
		return tree[cur] = init(cur * 2, start, mid, nums) + init(cur * 2 + 1, mid + 1, end, nums);
	}

	void updateLazy(const int cur, const int start, const int end) {
		if (lazy[cur] == 0) return;
		
		tree[cur] += lazy[cur] * (end - start + 1);
		if (start != end) {
			lazy[cur * 2] += lazy[cur];
			lazy[cur * 2 + 1] += lazy[cur];
		}
		lazy[cur] = 0;
	}

	void updateTree(int cur, int start, int end, const int left, const int right, const long long plus) {
		if (end < left || right < start) return;

		if (left <= start && end <= right) {
			lazy[cur] += plus;
			return;
		}

		updateLazy(cur, start, end);

		int mid = start + (end - start) / 2;
		updateTree(cur * 2, start, mid, left, right, plus);
		updateTree(cur * 2 + 1, mid + 1, end, left, right, plus);
		tree[cur] = tree[cur * 2] + tree[cur * 2 + 1];
	}

	long long query(int cur, int start, int end, const int left, const int right) {
		if (end < left || right < start) return 0;

		updateLazy(cur, start, end);

		if (left <= start && end <= right) return tree[cur];

		int mid = start + (end - start) / 2;
		return query(cur * 2, start, mid, left, right) + query(cur * 2 + 1, mid + 1, end, left, right);
	}
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> nums(N);
	for (int& num : nums) cin >> num;

	SegTree segTree(nums);

	int M, cmd, left, right, plus;
	cin >> M;

	while (M--) {
		cin >> cmd;

		if (cmd == 1) {
			cin >> left >> right >> plus;
			segTree.updateTree(1, 1, N, left, right, plus);
		}
		else if (cmd == 2) {
			cin >> left;
			cout << segTree.query(1, 1, N, left, left) << '\n';
		}
	}

	return 0;
}
