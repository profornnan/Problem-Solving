#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct UnionFind {
	vector<int> parent;

	UnionFind(int sz) : parent(sz, -1) {}

	int Find(int x) {
		if (parent[x] == -1) return x;
		return parent[x] = Find(parent[x]);
	}

	void Union(int a, int b) {
		int pa = Find(a);
		int pb = Find(b);
		if (pa == pb) return;
		parent[pa] = pb;
	}
};

int upperBound(const vector<int>& v, int target) {
	int left = 0;
	int right = v.size() - 1;

	while (left < right) {
		int mid = left + (right - left) / 2;

		if (v[mid] <= target)
			left = mid + 1;
		else
			right = mid;
	}

	return right;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, M, K;
	cin >> N >> M >> K;

	vector<int> cards(M);
	UnionFind uf(M);

	for (auto& card : cards)
		cin >> card;

	sort(cards.begin(), cards.end());

	for (int i = 0; i < K; ++i) {
		int num;
		cin >> num;

		int idx = uf.Find(upperBound(cards, num));

		if (idx + 1 < M)
			uf.Union(idx, idx + 1);

		cout << cards[idx] << '\n';
	}

	return 0;
}
