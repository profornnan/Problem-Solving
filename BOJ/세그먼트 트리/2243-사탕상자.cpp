#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

constexpr int MAX_F = 1'000'000;

struct SegTree {
	vector<int> tree;

	SegTree() {
		int h = ceil(log2(MAX_F));
		int sz = (1 << (h + 1));
		vector<int>(sz).swap(tree);
	}

	void update(int cur, int start, int end, const int idx, const int k) {
		if (end < idx || idx < start) return;

		if (start == end) {
			tree[cur] += k;
			return;
		}

		int mid = start + (end - start) / 2;
		update(cur * 2, start, mid, idx, k);
		update(cur * 2 + 1, mid + 1, end, idx, k);
		tree[cur] = tree[cur * 2] + tree[cur * 2 + 1];
	}

	int query(int cur, int start, int end, const int ranking) {
		--tree[cur];

		if (start == end)
			return start;

		int mid = start + (end - start) / 2;

		return ranking <= tree[cur * 2] ? query(cur * 2, start, mid, ranking) : query(cur * 2 + 1, mid + 1, end, ranking - tree[cur * 2]);
	}
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	SegTree segTree;

	for (int i = 0; i < N; ++i) {
		int cmd, ranking, flavor, num;

		cin >> cmd;

		if (cmd == 1) {
			cin >> ranking;
			cout << segTree.query(1, 1, MAX_F, ranking) << '\n';
		}
		else if (cmd == 2) {
			cin >> flavor >> num;
			segTree.update(1, 1, MAX_F, flavor, num);
		}
	}

	return 0;
}
