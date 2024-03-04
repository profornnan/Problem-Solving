#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class UnionFind {
private:
	vector<int> parent;

public:
	UnionFind(int sz) : parent(sz, -1) {}

	int Find(int x) {
		if (parent[x] == -1) return x;
		return parent[x] = Find(parent[x]);
	}

	void Union(int a, int b) {
		int pa = Find(a);
		int pb = Find(b);
		if (pa == pb) return;
		parent[pb] = pa;
	}

	int groupCnt() {
		int ret = 0;

		for (const auto& i : parent)
			if (i == -1)
				++ret;

		return ret;
	}
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	queue<pair<int, int>> q;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			char ch;
			cin >> ch;

			if (i < j && ch == 'Y')
				q.push({ i, j });
		}
	}

	if (q.size() < M) {
		cout << "-1\n";
		return 0;
	}

	UnionFind uf(N);
	vector<int> cnt(N);

	int sz = q.size();

	while (sz--) {
		const auto [i, j] = q.front();
		q.pop();

		if (uf.Find(i) == uf.Find(j)) {
			q.push({ i, j });
			continue;
		}

		uf.Union(i, j);
		++cnt[i];
		++cnt[j];
	}

	if (uf.groupCnt() != 1) {
		cout << "-1\n";
		return 0;
	}

	for (int k = 0; k < M - N + 1; ++k) {
		const auto [i, j] = q.front();
		q.pop();

		++cnt[i];
		++cnt[j];
	}

	for (int i = 0; i < N; ++i)
		cout << cnt[i] << ' ';
	cout << '\n';

	return 0;
}
