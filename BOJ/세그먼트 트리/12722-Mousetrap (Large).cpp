#include <iostream>
using namespace std;

constexpr int MAX_N = 1'000'000;
constexpr int MAX_BASE = 1'048'576;

int base;
int arr[MAX_N];
int tree[MAX_BASE * 2];

void init(const int N) {
	base = 1;

	while (base < N) base <<= 1;

	for (int i = 0; i < base; ++i)
		tree[base + i] = i < N;

	for (int i = base - 1; i > 0; --i)
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
}

void update(int idx, const int plus) {
	tree[idx += base] += plus;

	while (idx >>= 1)
		tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}

int query(int start, int end) {
	int ret = 0;

	for (start += base, end += base; start <= end; start >>= 1, end >>= 1) {
		if (start % 2 == 1) ret += tree[start++];
		if (end % 2 == 0) ret += tree[end--];
	}

	return ret;
}

int getIdx(int sum) {
	int idx = 1;

	while (idx < base) {
		if (tree[idx * 2] >= sum)
			idx = idx * 2;
		else {
			sum -= tree[idx * 2];
			idx = idx * 2 + 1;
		}
	}

	return idx - base;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cout << "Case #" << tc << ": ";

		int N;
		cin >> N;

		init(N);

		int idx = -1;

		for (int i = 1; i <= N; ++i) {
			idx = getIdx((query(0, idx) + i - 1) % tree[1] + 1);
			update(idx, -1);
			arr[idx] = i;
		}

		int M;
		cin >> M;

		for (int i = 0; i < M; ++i) {
			int idx;
			cin >> idx;
			cout << arr[idx - 1] << ' ';
		}

		cout << '\n';
	}

	return 0;
}
