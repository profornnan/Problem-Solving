#include <iostream>
using namespace std;

constexpr int MAX_N = 100'000;
constexpr int MAX_BASE = 262'144;

int base;
int id2idx[MAX_N + 1];
int tree[MAX_BASE * 2];

void init(const int N, const int M) {
	base = 1;

	while (base < N + M - 1) base <<= 1;

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

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int T;
	cin >> T;

	while (T--) {
		int N, M;
		cin >> N >> M;

		init(N, M);

		for (int i = 1; i <= N; ++i)
			id2idx[i] = N - i;

		for (int m = 0; m < M; ++m) {
			int id;
			cin >> id;

			cout << query(id2idx[id], N + m) - 1 << ' ';

			update(id2idx[id], -1);
			id2idx[id] = N + m;
			update(id2idx[id], 1);
		}

		cout << '\n';
	}

	return 0;
}
