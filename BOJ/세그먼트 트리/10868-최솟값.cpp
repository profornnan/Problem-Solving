#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Node {
	int start, end;
	int minNum;
};

struct SegTree {
	vector<int> nums;
	vector<Node> tree;

	SegTree(const vector<int>& nums) : nums(nums) {
		int sz = 1;
		while (sz < nums.size()) sz <<= 1;
		vector<Node>(sz << 1).swap(tree);
		init(1, 1, nums.size());
	}

	int init(int cur, int start, int end) {
		Node& node = tree[cur];

		node.start = start;
		node.end = end;

		if (start == end) return node.minNum = nums[start - 1];

		int mid = start + (end - start) / 2;
		return node.minNum = min(init(cur * 2, start, mid), init(cur * 2 + 1, mid + 1, end));
	}

	int query(int cur, int start, int end) {
		const Node& node = tree[cur];

		if (node.end < start || end < node.start) return 21e8;
		if (start <= node.start && node.end <= end) return node.minNum;

		int mid = start + (end - start) / 2;
		return min(query(cur * 2, start, end), query(cur * 2 + 1, start, end));
	}
};

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
	int N, M;
	cin >> N >> M;

	vector<int> nums(N);
	for (int& num : nums) cin >> num;

	SegTree segTree(nums);

	while (M--) {
		int start, end;
		cin >> start >> end;
		cout << segTree.query(1, start, end) << '\n';
	}

	return 0;
}
