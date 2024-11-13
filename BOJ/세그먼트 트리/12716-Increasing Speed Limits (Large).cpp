#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

constexpr int MOD = 1'000'000'007;
constexpr int MAX_N = 500'000;
constexpr int MAX_M = 100;
constexpr int MAX_BASE = 524'288;

int T, N, M, C;
long long X, Y, Z;
int arr[MAX_M];
int created[MAX_N];
int normalized[MAX_N];
int base, ans;
int tree[MAX_BASE * 2];

void init(const int sz) {
	memset(tree, 0, sizeof(tree));
	base = 1;
	while (base < sz) base <<= 1;
}

void update(int idx, const int plus) {
	idx += base;
	tree[idx] = (tree[idx] + plus) % MOD;

	while (idx >>= 1)
		tree[idx] = (tree[idx * 2] + tree[idx * 2 + 1]) % MOD;
}

int query(int start, int end) {
	int ret = 0;

	for (start += base, end += base; start <= end; start >>= 1, end >>= 1) {
		if (start % 2 == 1) ret = (ret + tree[start++]) % MOD;
		if (end % 2 == 0) ret = (ret + tree[end--]) % MOD;
	}

	return ret;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cin >> N >> M >> X >> Y >> Z;

		for (int i = 0; i < M; ++i)
			cin >> arr[i];

		for (int i = 0; i < N; ++i) {
			created[i] = normalized[i] = arr[i % M];
			arr[i % M] = (X * arr[i % M] + Y * (i + 1)) % Z;
		}

		sort(created, created + N);
		C = unique(created, created + N) - created;

		for (int i = 0; i < N; ++i)
			normalized[i] = lower_bound(created, created + C, normalized[i]) - created;

		init(C);
		ans = 0;

		for (int i = 0; i < N; ++i) {
			const int plus = query(0, normalized[i] - 1) + 1;
			update(normalized[i], plus);
			ans = (ans + plus) % MOD;
		}

		cout << "Case #" << tc << ": " << ans << '\n';
	}

	return 0;
}
