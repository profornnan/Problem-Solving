#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

constexpr int MOD = 1'000'000'007;

struct SegTree {
	vector<int> tree;

	SegTree(const vector<int>& nums) {
		int h = ceil(log2(nums.size()));
		int sz = (1 << (h + 1));

		vector<int>(sz, 1).swap(tree);

		init(1, 1, nums.size(), nums);
	}

	int init(int cur, int start, int end, const vector<int>& nums) {
		if (start == end) return tree[cur] = nums[start - 1];

		int mid = start + (end - start) / 2;
		return tree[cur] = (static_cast<long long>(init(cur * 2, start, mid, nums)) * init(cur * 2 + 1, mid + 1, end, nums)) % MOD;
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
		tree[cur] = (static_cast<long long>(tree[cur * 2]) * tree[cur * 2 + 1]) % MOD;
	}

	int query(int cur, int start, int end, const int left, const int right) {
		if (right < start || end < left) return 1;
		if (left <= start && end <= right) return tree[cur];

		int mid = start + (end - start) / 2;
		return (static_cast<long long>(query(cur * 2, start, mid, left, right)) * query(cur * 2 + 1, mid + 1, end, left, right)) % MOD;
	}
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, M, K;
	cin >> N >> M >> K;

	vector<int> nums(N);
	for (auto& num : nums) cin >> num;

	SegTree segTree(nums);

	for (int i = 0; i < M + K; ++i) {
		int cmd, left, right, idx, num;

		cin >> cmd;

		if (cmd == 1) {
			cin >> idx >> num;
			segTree.update(1, 1, N, idx, num);
		}
		else if (cmd == 2) {
			cin >> left >> right;
			cout << segTree.query(1, 1, N, left, right) << '\n';
		}
	}

	return 0;
}
