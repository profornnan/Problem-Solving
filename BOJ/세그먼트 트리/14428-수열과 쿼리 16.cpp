#include <iostream>
#include <algorithm>
using namespace std;

constexpr int INF = 21e8;
constexpr int MAX_BASE = 131'072;

struct Node {
	int minIdx;
	int minNum;

	bool operator<(const Node& rhs) const {
		return minNum != rhs.minNum ? minNum < rhs.minNum : minIdx < rhs.minIdx;
	}
};

int base;
Node tree[MAX_BASE * 2];

void init(const int N) {
	base = 1;

	while (base < N - 1) base <<= 1;

	for (int i = 0; i < N; ++i) {
		tree[base + i].minIdx = i + 1;
		cin >> tree[base + i].minNum;
	}

	for (int i = N; i < base; ++i)
		tree[base + i].minNum = INF;

	for (int i = base - 1; i > 0; --i)
		tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
}

void update(int idx, const int num) {
	tree[idx += base].minNum = num;

	while (idx >>= 1)
		tree[idx] = min(tree[idx * 2], tree[idx * 2 + 1]);
}

int query(int start, int end) {
	Node res = { 0, INF };

	for (start += base, end += base; start <= end; start >>= 1, end >>= 1) {
		if (start % 2 == 1) res = min(res, tree[start++]);
		if (end % 2 == 0) res = min(res, tree[end--]);
	}

	return res.minIdx;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	init(N);

	int M;
	cin >> M;

	for (int i = 0; i < M; ++i) {
		int cmd, idx, num, st, en;

		cin >> cmd;

		if (cmd == 1) {
			cin >> idx >> num;
			update(idx - 1, num);
		}
		else if (cmd == 2) {
			cin >> st >> en;
			cout << query(st - 1, en - 1) << '\n';
		}
	}

	return 0;
}
