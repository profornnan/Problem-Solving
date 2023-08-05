#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

constexpr int INF = 21e8;

struct Node {
	int minNum;
	int maxNum;
};

struct SegTree {
	vector<Node> tree;

	SegTree(const vector<int>& nums) {
		int h = ceil(log2(nums.size()));
		int sz = (1 << (h + 1));

		vector<Node>(sz).swap(tree);

		init(1, 1, nums.size(), nums);
	}

	Node init(int cur, int start, int end, const vector<int>& nums) {
		if (start == end) return tree[cur] = { nums[start - 1], nums[start - 1] };

		int mid = start + (end - start) / 2;

		Node leftChild = init(cur * 2, start, mid, nums);
		Node rightChild = init(cur * 2 + 1, mid + 1, end, nums);

		return tree[cur] = { min(leftChild.minNum, rightChild.minNum), max(leftChild.maxNum, rightChild.maxNum) };
	}

	Node query(int cur, int start, int end, const int left, const int right) {
		if (right < start || end < left) return { INF, 0 };
		if (left <= start && end <= right) return tree[cur];

		int mid = start + (end - start) / 2;

		Node leftChild = query(cur * 2, start, mid, left, right);
		Node rightChild = query(cur * 2 + 1, mid + 1, end, left, right);

		return { min(leftChild.minNum, rightChild.minNum), max(leftChild.maxNum, rightChild.maxNum) };
	}
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<int> nums(N);
	for (int& num : nums) cin >> num;

	SegTree segTree(nums);

	for (int i = 0; i < M; ++i) {
		int left, right;
		cin >> left >> right;
		auto [minNum, maxNum] = segTree.query(1, 1, N, left, right);
		cout << minNum << ' ' << maxNum << '\n';
	}

	return 0;
}
