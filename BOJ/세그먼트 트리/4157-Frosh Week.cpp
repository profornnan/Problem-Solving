#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

constexpr int MAX_BASE = 1'048'576;

int base;
int tree[MAX_BASE * 2];

void init(const int N) {
	base = 1;
	while (base < N) base <<= 1;
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

	int N;
	cin >> N;

	vector<int> arr(N);

	for (auto& num : arr)
		cin >> num;

	vector<int> sorted = arr;
	sort(sorted.begin(), sorted.end());

	init(N);
	long long ans = 0;

	for (auto& num : arr) {
		num = lower_bound(sorted.begin(), sorted.end(), num) - sorted.begin();
		ans += query(num + 1, N - 1);
		update(num, 1);
	}

	cout << ans << '\n';

	return 0;
}
