#include <iostream>
#include <algorithm>
using namespace std;

constexpr int INF = 21e8;
constexpr int MAX_BASE = 65'536;

struct Node {
	int minNum;
	int maxNum;
};

int base;
Node tree[MAX_BASE * 2];

void init(const int N) {
	base = 1;

	while (base < N - 1) base <<= 1;

	for (int i = 0; i < N; ++i) {
		auto& [minNum, maxNum] = tree[base + i];
		cin >> minNum;
		maxNum = minNum;
	}

	for (int i = base - 1; i > 0; --i) {
		auto& now = tree[i];
		const auto& left = tree[i * 2];
		const auto& right = tree[i * 2 + 1];

		now.minNum = min(left.minNum, right.minNum);
		now.maxNum = max(left.maxNum, right.maxNum);
	}
}

Node query(int start, int end) {
	int minNum = INF;
	int maxNum = 0;

	for (start += base, end += base; start <= end; start >>= 1, end >>= 1) {
		if (start % 2 == 1) {
			minNum = min(minNum, tree[start].minNum);
			maxNum = max(maxNum, tree[start].maxNum);
			++start;
		}

		if (end % 2 == 0) {
			minNum = min(minNum, tree[end].minNum);
			maxNum = max(maxNum, tree[end].maxNum);
			--end;
		}
	}

	return { minNum, maxNum };
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, Q;
	cin >> N >> Q;

	init(N);

	for (int i = 0; i < Q; ++i) {
		int st, en;
		cin >> st >> en;
		const auto [minNum, maxNum] = query(st - 1, en - 1);
		cout << maxNum - minNum << '\n';
	}

	return 0;
}
