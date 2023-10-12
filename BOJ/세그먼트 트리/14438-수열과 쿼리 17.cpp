#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

constexpr int INF = 21e8;

struct SegTree {
	vector<int> tree;

	SegTree(const vector<int>& nums) {
		int h = ceil(log2(nums.size()));
		int sz = (1 << (h + 1));

		vector<int>(sz).swap(tree);

		init(1, 1, nums.size(), nums);
	}

	int init(int cur, int start, int end, const vector<int>& nums) {
		if (start == end) return tree[cur] = nums[start - 1];

		int mid = start + (end - start) / 2;
		return tree[cur] = min(init(cur * 2, start, mid, nums), init(cur * 2 + 1, mid + 1, end, nums));
	}

	void update(int cur, int start, int end, const int left, const int right, const int num) {
		if (end < left || right < start) return;

		if (start == end) {
			tree[cur] = num;
			return;
		}

		int mid = start + (end - start) / 2;
		update(cur * 2, start, mid, left, right, num);
		update(cur * 2 + 1, mid + 1, end, left, right, num);
		tree[cur] = min(tree[cur * 2], tree[cur * 2 + 1]);
	}

	int query(int cur, int start, int end, const int left, const int right) {
		if (end < left || right < start) return INF;
		if (left <= start && end <= right) return tree[cur];

		int mid = start + (end - start) / 2;
		return min(query(cur * 2, start, mid, left, right), query(cur * 2 + 1, mid + 1, end, left, right));
	}
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> nums(N);
	for (int& num : nums) cin >> num;

	SegTree segTree(nums);

	int M, cmd, idx, num, left, right;
	cin >> M;

	while (M--) {
		cin >> cmd;

		if (cmd == 1) {
			cin >> idx >> num;
			segTree.update(1, 1, N, idx, idx, num);
		}
		else if (cmd == 2) {
			cin >> left >> right;
			cout << segTree.query(1, 1, N, left, right) << '\n';
		}
	}

	return 0;
}
